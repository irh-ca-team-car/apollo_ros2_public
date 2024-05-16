const { ConsoleWriter } = require("istanbul-lib-report");

function pbtxt(data, file) {
    //fs.readFileSync

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
                    //if (mapping[value])
                    //    value = mapping[value];
                    if (value.match) {
                        if (value.toUpperCase().match(/^([A-Z_]+)$/) && !(value.indexOf('"') >= 0) && value != "true" && value != "false") {
                            value = "\"" + value + "\"";
                        }
                    }
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
    try {
        return JSON.parse(json_version);
    }
    catch (err) {
        if (err.message.indexOf("at") >= 1) {
            var idx = parseInt(err.message.split(' ').reverse()[0])
            console.error(err.message, file);
            console.log(json_version.substring(idx-50,idx+50));
        }
        return {};
    }
}
function h(file, protofile, protoType) {
    var protobuf = require("protobufjs");
    var fs = require("fs")
    var fsp = fs.promises
    var buffer = fs.readFileSync(file);

    var root = protobuf.loadSync(protofile);


    var AwesomeMessage = root.lookupType(protoType);
    var err = AwesomeMessage.verify(buffer);
    if (err) {
        console.error("Problem", err);
        return
    }
    var msg = {};
    try {
        msg = AwesomeMessage.decode(
            buffer
        );
    }
    catch
    {
        msg = pbtxt(buffer, file);
        function matchPrefix(name) {
            var arr = ["apollo.perception.inference.", ""].map(x => {
                try {
                    return root.lookupType(x + name)
                } catch { return null; }
            }
            )
            for (var i = 0; i < arr.length; i++) {
                if (arr[i])
                    if (arr[i].name == name)
                        return arr[i];
            }
            return null;
        }
        function handle(messageType, value, show) {
            if (!value) return;

            messageType.fieldsArray.forEach(f => {

                var val = value[f.name.toLowerCase().replace("_", "")];

                if (f.repeated && val && !(val instanceof Array)) {
                    val = [val];
                }
                if (val) {
                    if (!f.resolvedType) {
                        f.resolvedType = matchPrefix(f.type);
                    }
                    if (f.resolvedType) {
                        if (f.repeated) {
                            val = val.map(el => handle(f.resolvedType, el))
                        }
                        else {
                            val = handle(f.resolvedType, val);
                        }

                        if (val !== undefined)
                            value[f.name] = val;
                    }
                    else
                        value[f.name] = val;
                }
            });
            if (show)
                console.log(messageType.name, value);
            return value;
        }
        //console.log(msg.layer[0]);
        msg = handle(AwesomeMessage, msg);
        //console.log(msg.layer[0]);

        //console.log(msg);
        msg = AwesomeMessage.fromObject(msg);

    }

    function toJSON(msg) {
        var obj = {};

        Object.keys(msg).forEach(param => {
            var param_l = param.toLowerCase().replace("_", "")
            if (msg[param] instanceof protobuf.Message) {
                obj[param_l] = toJSON(msg[param])
            }
            else if (msg[param] instanceof Array) {
                obj[param_l] = msg[param].map(u => {
                    if (u instanceof protobuf.Message)
                        return toJSON(u);
                    return u;
                })
            }
            else
                obj[param_l] = msg[param]
        });

        return obj;
    }
    fs.writeFileSync(file + ".json", JSON.stringify(toJSON(msg), null, '\t'));
}


data =
    [
        [
            "data/perception/lidar/models/cnnseg/velodyne128/deploy.caffemodel",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-r2/deploy.model",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-r4/deploy.model",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-r4-half/deploy.model",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/lane_detector/darkSCNN/deploy.prototxt",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/lane_detector/darkSCNN/deploy.caffemodel",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/camera/models/lane_detector/darkSCNN/deploy.prototxt",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/camera/models/lane_detector/darkSCNN/deploy.caffemodel",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-r4-half/deploy.pt",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-yolo/deploy.pt",
            "/mnt/sd/git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter"
        ]
    ]

data.forEach(dt => h(dt[0], dt[1], dt[2]));