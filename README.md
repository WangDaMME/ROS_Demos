# ROS_Demos

## Project 3 - ROS Voice Interaction
Based on the iFlyTek open-source Voice Navigation package, Ros is interacted with voice by 'iat_publish' node (transfer Recognized Speech to String) and 'tts_subsceibe' (input String and output Speech).

1. iat Node.<br>
   Waiting for the WakeUp signal --> listen to the Speech input --> Recognization --> Output the String.
<div align="center">
<img src="https://github.com/WangDaMME/ROS_Demos/blob/master/catkin_ws_voice/voice_result_gif/iat.gif" width="600" height="400">
</div>
</div>

2. tts Node.<br>
   Waiting for the WakeUp signal --> input the String --> Recognization --> Output the Voice.
<div align="center">
<img src="https://github.com/WangDaMME/ROS_Demos/blob/master/catkin_ws_voice/voice_result_gif/tts.gif" width="600" height="400">
</div>

3. Repeat Voice Demo.<br>
   Waiting for the WakeUp signal --> input the Speech --> Recognization --> Repeat after the Speech.
<div align="center">
<a href="https://www.youtube.com/watch?v=V6Msm9cNnYM" target="_blank">Repeat Voice Demo </a>
</div>

4. Voice Attendant. <br>
   Recognize the speech and use the method of "Matching the key word" to respond to corresponding input questions, ie. What is the robot's age, function, what time it is now?...
<div align="center">
<a href="https://www.youtube.com/watch?v=uXRiw2IMd9Q" target="_blank"> Voice Assistant Demo </a>
</div>

<hr>

<h3> Project 1 - ROS Communication (Topic/Service) </h3>
1. Create a Publisher and command the turtle for circular motion
   Create a Subsciber node to display its pose info.
<div align="center">
<img src="demo1/catkin_ws/res_gif/topic.gif" width="600" height="400">
</div>

2. Create a Server node and give birth to a new turtle.
<div align="center">
<img src="demo1/catkin_ws/res_gif/birth.gif" width="600" height="400">
</div>

3. Give birth to a new turtle & Command the motion of the turtle via Command Prompt.
<div align="center">
<img src="demo1/catkin_ws/res_gif/cmd_create.gif" width="600">
</div>
</hr>

