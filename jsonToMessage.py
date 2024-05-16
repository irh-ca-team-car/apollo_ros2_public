import json
import rclpy
import rclpy.serialization
from apollo_msgs.msg import *
files =[
        [
             "data/perception/lidar/models/cnnseg/velodyne128/deploy.caffemodel.json",
             "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
             "apollo.perception.inference.NetParameter",
             "ApolloperceptioninferenceNetParameter"
         ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-r2/deploy.model.json",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter",
            "ApolloperceptioninferenceNetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-r4/deploy.model.json",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter",
            "ApolloperceptioninferenceNetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-r4-half/deploy.model.json",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter",
            "ApolloperceptioninferenceNetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-r4-half/deploy.pt.json",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter",
            "ApolloperceptioninferenceNetParameter"
        ],
        [
            "data/perception/production/data/perception/camera/models/yolo_obstacle_detector/3d-yolo/deploy.pt.json",
            "/mnt/sd/git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter",
            "ApolloperceptioninferenceNetParameter"
        ],
          [
             "data/perception/production/data/perception/camera/models/lane_detector/darkSCNN/deploy.prototxt.json",
             "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
             "apollo.perception.inference.NetParameter",
             "ApolloperceptioninferenceNetParameter"
         ],
        [
            "data/perception/production/data/perception/camera/models/lane_detector/darkSCNN/deploy.caffemodel.json",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter",
            "ApolloperceptioninferenceNetParameter"
        ],
        [
            "data/perception/camera/models/lane_detector/darkSCNN/deploy.prototxt.json",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter",
            "ApolloperceptioninferenceNetParameter"
        ],
        [
            "data/perception/camera/models/lane_detector/darkSCNN/deploy.caffemodel.json",
            "/mnt/sd//git/apollo/modules/perception/proto/rt.proto",
            "apollo.perception.inference.NetParameter",
            "ApolloperceptioninferenceNetParameter"
        ]
    ]
for arr in files:
    fname= arr[0]
    fname_end = arr[0].replace(".json",".bin")
    print(arr)
    type_=arr[3]

    with open(fname) as f:
        data = json.load(f)
        pass
    msg = eval(type_+"()")
    def convertTo(value,type_):
        #print("Converting ",type(value),"to",type_)
        if type_ == "int":
            #print(value)
            return int(value.low)
        if type_ == "float":
            #print(value)
            return float(value)
        arr_obj = eval(type_+"()")
        put(value,arr_obj)
        return arr_obj
    def put(data,destination):
        for attr, value in data.items():
            if attr == "dim":
                value = [x["low"] for x in value]
            try:
                setattr(destination,attr,value)
            except Exception as e:
                str_ = str(e)
                #print(e)
                if "must be a set or sequence" in str_:
                    type_ = str_.split("'")[-2]
                    arr=[]
                    #print("Attempting to solve array of ",type_)
                    for obj_b in value:
                        arr.append(convertTo(obj_b,type_))
                    setattr(destination,attr,arr)
                elif "must be a sub message of type" in str_:
                    type_ = str_.split("'")[-2]
                    #print("Attempting to solve message of ",type_)
                    setattr(destination,attr,convertTo(value,type_))
                
    put(data,msg)

    #print(msg)

    seri = rclpy.serialization.serialize_message(msg)

    print(fname_end)
    f = open(fname_end, "wb")
    f.write(seri)
    f.flush()
    f.close()


    f = open(fname_end, "rb")
    bts = f.read()
    rclpy.serialization.deserialize_message(bts,msg)
    f.close()