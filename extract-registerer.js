const fs = require("fs")
const path = require("path")
const { exit } = require("process")

const getAllFiles = function (dirPath, arrayOfFiles, ends) {
    files = fs.readdirSync(dirPath)

    arrayOfFiles = arrayOfFiles || []

    files.forEach(function (file) {
        if (fs.statSync(dirPath + "/" + file).isDirectory()) {
            arrayOfFiles = getAllFiles(dirPath + "/" + file, arrayOfFiles, ends)
        } else {
            if (file.endsWith(ends))
                arrayOfFiles.push(path.join(dirPath, "/", file))
        }
    })

    return arrayOfFiles
}

//PERCEPTION_REGISTER_REGISTERER(BaseOneShotTypeFusion);
//#define PERCEPTION_REGISTER_ONESHOTTYPEFUSION(name)
registerers = []

function findAllRegisterers(filename) {
    var regex_g = /PERCEPTION_REGISTER_REGISTERER\(([A-Za-z_]+)\);\s+#define ([A-Z_]+)/g;
    var regex_l = /PERCEPTION_REGISTER_REGISTERER\(([A-Za-z_]+)\);\s+#define ([A-Z_]+)/;
    try {
        data = fs.readFileSync(filename);
        //console.log(filename);
        var content = data.toString();
        var matches = content.match(regex_g);
        if (matches) {
            matches.forEach(element => {
                var name = element.match(regex_l)[2];
                registerers.push(name);
            });
            //fs.writeFileSync(filename, content, (err) => console.log(err));
        }
        return filename;
    }
    catch (exx) {
        //console.error(filename,exx);
        return filename;
    }
}

getAllFiles(__dirname, [], ".h").map(findAllRegisterers);
console.log(registerers);
var factories = []

getAllFiles(__dirname, [], ".cpp").map(findAllRegisterersImplementation);

function findAllRegisterersImplementation(filename) {
    data = fs.readFileSync(filename);
    var content = data.toString();

    registerers.forEach(element => {
        var regex_str = eval("/"+element + "\\(([A-Za-z_]+)\\);/");
        var regex_g = new RegExp(regex_str, "g");
        var regex_l = new RegExp(regex_str);
        var match = content.match(regex_l);
        if (match) {
            var name = match[1];
            factories.push(findCurrentNamespace(content.substring(0, match.index))+"::"+name);
        }
    });

    return filename;
}

var header = "void InitFactories();"
var body = "";
factories.forEach(factoryName => {
    var name = factoryName.split("::").reverse()[0];
    var namespace = factoryName.split("::").reverse().splice(1).reverse().join("::");
    body += "namespace "+namespace+"{bool RegisterFactory" + name + "();}\r\n";
})
body += "void InitFactories(){\r\n";
factories.forEach(factoryName => {
    var name = factoryName.split("::").reverse()[0];
    var namespace = factoryName.split("::").reverse().splice(1).reverse().join("::");
    body += "  "+namespace+"::RegisterFactory" + name + "();\r\n";
})
body += "}";

console.log(header, body);
//__attribute__((constructor)) bool RegisterFactory##name()

fs.writeFileSync(path.join(__dirname, "include", "modules", "perception", "factories.h"), header, console.error);
fs.writeFileSync(path.join(__dirname, "src", "modules", "perception", "factories.cpp"), body, console.error);

getAllFiles(__dirname, [], ".cpp").map(moveRegistererAfterNamespace);

function findCurrentNamespace(content)
{
    let reg = /namespace ([a-zA-Z]+)/g;
    return content.match(reg).map(d => {
        return d.match(/namespace ([a-zA-Z]+)/)[1];
    }).join("::");
}
function moveRegistererAfterNamespace(filename)
{
    data = fs.readFileSync(filename);
    var content = data.toString();
    let reg = /([A-Z_]+\([a-zA-Z]+\));(\s+}[ /a-zA-Z]+){3}/;
    var match = content.match(reg);
    if (match) {
        console.log(match.index);
        console.log(findCurrentNamespace(content.substring(0, match.index)));
        /*content = content.replace(reg, function (match) {
            match = match.match(reg);
            //console.log(match);
            return "}\r\n}\r\n}\r\n" + match[1] + ";";
        });*/
        //console.log(content);
        //fs.writeFileSync(filename, content, console.error);
    }

    

} 