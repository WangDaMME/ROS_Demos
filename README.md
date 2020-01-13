# ROS_Demos

<hr>
## Project 3 - ROS Voice Navigation
Based on the iFlyTek open-source Voice Navigation package, Ros is interacted with voice by 'iat_publish' node (transfer Recognized Speech to String) and 'tts_subsceibe' (input String and output Speech).

1. iat Node.
   Waiting for the WakeUp signal --> listen to the Speech input --> Recognization --> Output the String.
<div align="center">
<img src="catkin_ws_voice/voice_res_gif/iat.gif" width="600" height="400">
</div>

2. tts Node.
   Waiting for the WakeUp signal --> input the String --> Recognization --> Output the Voice.
<div align="center">
<img src="catkin_ws_voice/voice_res_gif/tts.gif" width="600" height="400">
</div>




<hr>
## Project 1 - ROS Communication (Topic/Service)
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

