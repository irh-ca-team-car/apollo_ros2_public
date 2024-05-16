ros2 topic list > topic.list.txt
echo "" > topic.info.txt
file="topic.list.txt"
while read line; do
  echo ${line} | tee -a topic.info.txt
  ros2 topic info ${line} | tee -a topic.info.txt
done < "${file}"
