const fs = require("fs")

content = JSON.parse(fs.readFileSync("config_manager1.json").toString())

console.log(content);

content.modelconfigs.forEach(element => {
    params = element.stringparams;
    if(params)
        params.forEach(param=>{
            param.value = new Buffer(param.value,'base64').toString('ascii')
            console.log(param)
        })
});

fs.writeFileSync("config_manager2.json",JSON.stringify(content))