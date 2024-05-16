const fs = require("fs")
const path = require("path")
const { exit } = require("process")

const getAllFiles = function (dirPath, arrayOfFiles, ends) {
    if (fs.statSync(dirPath).isDirectory()) {
        files = fs.readdirSync(dirPath)

        arrayOfFiles = arrayOfFiles || []

        files.forEach(function (file) {
            if (fs.statSync(path.join(dirPath, file)).isDirectory()) {
                getAllFiles(path.join(dirPath, file), arrayOfFiles, ends)
            } else {
                if (file.endsWith(ends))
                    arrayOfFiles.push(path.join(__dirname, dirPath, "/", file))
            }
        })
    }
    return arrayOfFiles
}


headers = getAllFiles(".", [], ".pb.h");
mapping = {};
function readHeader(filename) {
    data = fs.readFileSync(filename);
    regex = /([A-Z_]+) = ([0-9])/g
    regex_indiv = /([A-Z_]+) = ([0-9])/
    matches = data.toString().match(regex);
    if (matches) {
        matches.forEach((d, i) => {
            match = d.match(regex_indiv);
            var name = match[1];
            var value = match[2];
            if (mapping[name]) mapping[name] = name;
            else mapping[name] = value;
        });
    }
}
headers.map(readHeader);
files = getAllFiles(".", [], ".pb.txt");
function convertFile(filename) {
    //fs.readFileSync
    data = fs.readFileSync(filename);

    if (data.length > 1000000) return filename;
    output_filename = filename.replace(".pb.txt", ".json").replace(".pt", ".json").replace(".prototxt", ".json");
    if (fs.existsSync(output_filename))
        return filename;

    console.log(filename);
    content = (data.toString());
    var json_version;

    try {

        json_version = JSON.stringify(JSON.parse(content));
    } catch {
        function handleBlock(content) {
            var obj = {};
            var pos = 0;
            var name = ""
            while (pos < content.length) {
                function skipWhiteChar() {
                    //console.log("skipWhiteChar", content.substr(pos, 10));

                    var c = content[pos];
                    while (pos < content.length && (c == " " || c == "\t" || c == "\r" || c == "\n")) { pos++; c = content[pos] }
                }
                function grabUntilSpace() {
                    //console.log("grabUntilSpace", content.substr(pos, 10));
                    var c = content[pos];
                    var value = "";
                    while (pos < content.length && (c != " " && c != "\t" && c != "\r" && c != "\n")) { value += c; pos++; c = content[pos] }
                    return value;
                }
                function grabUntilEndOfBlock() {
                    //console.log("grabUntilEndOfBlock", content.substr(pos, 10));
                    var c = content[pos];
                    var value = "";
                    var countBlock = 0;

                    while (pos < content.length && countBlock >= 0) {
                        if (c == "{")
                            countBlock++;
                        if (c == "}")
                            countBlock--;
                        value += c; pos++; c = content[pos]
                    }
                    return handleBlock(value);
                }
                function grabUntilEndOfLine() {
                    //console.log("grabUntilEndOfLine", content.substr(pos, 10));

                    var c = content[pos];

                    while (pos < content.length) {
                        if (c == '\r' || c == '\n')
                            break;
                        pos++; c = content[pos]
                        //console.log("Waiting for end of line", c);
                    }
                }
                function readString() {
                    //console.log("readString", content.substr(pos, 10));
                    value = "";
                    var c = content[pos];
                    var stringChar = c;
                    var countBlock = 1;
                    while (pos < content.length && countBlock >= 0) {
                        if (c == stringChar)
                            countBlock--;
                        value += c; pos++; c = content[pos]
                    }
                    //console.log(value);
                    return value;
                }
                function readValue() {
                    //console.log("readValue", content.substr(pos, 10));

                    var c = content[pos];
                    skipWhiteChar();
                    c = content[pos];
                    if (c == "\"" || c == "'")
                        return readString();
                    return grabUntilSpace();
                }

                function put(name, value) {
                    //console.log("PUT", name, value)
                    if (mapping[value])
                        value = mapping[value];
                    if (!obj[name]) {
                        obj[name] = value;
                    }
                    else {
                        if (obj[name] instanceof Array) {
                            obj[name].push(value);
                        }
                        else {
                            obj[name] = [obj[name], value];
                        }
                    }
                }
                var c = content[pos]
                if (c == ":") {
                    pos++;
                    name = name.trim().replace(/_/g, "");
                    value = readValue();
                    if (value == "{")
                        value = grabUntilEndOfBlock();
                    put(name, value);
                    name = "";
                }
                else if (c == "{") {
                    pos++;
                    name = name.trim().replace(/_/g, "");
                    value = grabUntilEndOfBlock();
                    put(name, value);
                    name = "";
                }
                else if (c == "#") {
                    grabUntilEndOfLine();
                    c = content[pos]
                }
                else
                    name += c;
                //console.log(pos, content[pos])
                pos++;

            }
            return obj;
        }
        var obj = handleBlock(content);
        function createString(obj) {
            var str = "";
            if (obj instanceof String) {
                str += obj;
            }
            else if (obj instanceof Array) {
                str += "[";
                str += (obj.map(value => createString(value))).join(',');
                str += "]";
            }
            else if (obj instanceof Object) {
                str += "{";
                str += (Object.keys(obj).map(key => '"' + key + '": ' + createString(obj[key]))).join(',');
                str += "}";
            } else {
                str += obj.toString();
            }
            return str;
        }
        json_version = (createString(obj));
    }
    try {
        json_version = JSON.stringify(JSON.parse(json_version), null, '\t')
    } catch {

    }

    fs.writeFileSync(output_filename, json_version, (err) => console.log);
    //if (filename.indexOf(".pb.txt") != -1)
    //    fs.unlinkSync(filename);

}
getAllFiles(".", [], ".pb.txt").map(convertFile)
getAllFiles(".", [], ".prototxt").map(convertFile)
//getAllFiles(".", [], ".pt").map(convertFile)
getAllFiles(".", [], ".json").map(mappingInJson).map(validateJson);
function mappingInJson(filename) {
    data = fs.readFileSync(filename);

    content = data.toString().replace(/: ([A-Z_]+)/g, function (reg) {
        var key = reg.match(/: ([A-Z_]+)/)[1];
        if (mapping[key])
            return ": " + mapping[key];
        return reg;
    });
    //console.log(content);
    try {
        content = JSON.stringify(JSON.parse(content), null, '\t')
    } catch {

    }
    fs.writeFileSync(filename, content, (err) => console.log(err));
    return filename;
}
function validateJson(filename) {
    data = fs.readFileSync(filename);
    {
        content = (data.toString());
        try {
            JSON.parse(content);
        } catch (err) {
            console.error(filename, "is not valid json")
        }
    }
}
var missing = {}

getAllFiles(".", [], ".cpp").map(checkForPbTxt).map(validatePath);
getAllFiles(".", [], ".h").map(checkForPbTxt).map(validatePath);
getAllFiles(".", [], ".yaml").map(checkForPbTxt).map(validatePath);
getAllFiles("../apollo_launch", [], ".yaml").map(checkForPbTxt).map(validatePath);

function checkForPbTxt(filename) {
    data = fs.readFileSync(filename);

    var content = data.toString();
    var matches = content.match(/.pb.txt/g);
    if (matches) {
        console.log(filename, "contains", matches.length, ".pb.txt");
        content = content.replace(/.pb.txt/g, ".json");
        fs.writeFileSync(filename, content, (err) => console.log(err));

    }
    return filename;
}

function validatePath(filename) {
    data = fs.readFileSync(filename);

    var content = data.toString();
    var matches = content.match(/<root>(.*).json/g);
    if (matches) {
        matches.forEach(element => {
            try {
                var path = element;
                path = path.replace("<root>", ".");
                fs.accessSync(path);
            }
            catch {
                if (missing[element]) {
                    missing[element].push(filename);
                }
                else
                    missing[element] = [filename];
            }
        });
        //console.log(filename, "contains", matches.length, "paths");
    }
    return filename;
}
console.error(missing);
