# arduino-rfid

This is a door loock using arduino mega, RFID-RC522 and a servo motor. Code is inclueded, file rfid_sensor.

Here is a video: https://youtu.be/a2WvPmyuhfg

Here the improved version (with lcd 16x2 screen): https://youtu.be/uswi5w1OYw8

Explanation:

When you use the blue 'card' the motor doesn't move and the red light turns on.

When you use the white card the green light turns on, the servo motor moves and after 5 seconds it moves again to the first position. During the motor movement, the blue light is on. If you create some mecanism that when the servo moves it opens a loock, then you enter the room and after 5 seconds it closes the door. Once you are inside, you need to open the door again from the inside. So you use the button.

The button does exacly the same as the white card but from the inside.

The explanation file are pictures and the pin numbers of each cable.
