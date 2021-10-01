# Habit Tracker

The Habit Tracker is a minimalistic app that holds the user accountable for completing certain habits throughout each day of the week. 
The user can type up a note and import it to the app, where the app will read in the file and display the specified habits, one per day.
The user can also add accomplishments for each day as a result of completing the corresponding habit as
positive reinforcement. As each habit stays unchecked with checkboxes near each label for the days of the week, 
a timer starts to encourage the user to complete the unfinished habit. The timer stops when the habit is completed and the user can 
move to the next day when they're ready. 

## Installation of Cinder, Cmake, and CLion

Follow the instructions on https://cmake.org/download/, https://libcinder.org/download, and https://www.jetbrains.com/clion/download/ to find the fit for your operating system. You can also install Cmake into 
your current directory with these commands. 

```bash
  cmake .
  make      
  make install
```

## Setting up Cinder
After you've downloaded the Cinder package (v0.9.2), create a folder named Cinder
and extract the downloaded package into it. 

Then open the Cinder folder in CLion and click the green play button to build libcinder. 
Open the following directory in a new window in CLion and click the green play button again to test that you are able to see the Cinder sample display. 
```bash 
/Cinder/samples/BasicApp 
```

## Setting up project repository

After the Cinder setup, you can now create a directory within the Cinder directory.
You can create a sub folder called my-projects for example. Then clone the app repository with this link into the folder using these commands:
```bash 
cd Cinder 
mkdir my-projects
cd my-projects
git clone https://github.com/uiuc-sp21-cs126/final-project-sm202073.git
```

## Run Configuration and Data
When opening the app and trying to run, makes sure you choose **FinalProject** as the run configuration in the top right menu bar
next to the green play button. Then click the play button to see the Cinder window pop up.
It should be a gray screen with orange calendar blocks for each day of the week. A timer will also start running,
as the app defaults to being set to Monday. To change the habits to cater to your own needs,
write down days of the week followed by a habit on the next line and a space between consecutive days. Drag the file you wrote on
to the **/data** folder in the project directory on CLion. Do the same for accomplishments on corresponding days. A template habit file is below:
```bash 
Monday
Start week off well

Tuesday
Prepare for productivity

Wednesday
Take a mid-week break

Thursday
Finish strong

Friday
Relax with loved ones
```
Here's a template accomplishment file:
```bash 
Monday
Got off to a great start

Tuesday
Planned ahead

Wednesday
Got some free time

Thursday
Made progress on classes

Friday
Spent time with family
```

## Navigating the UI
After you run the UI, it starts on Monday and sets the timer for that habit. You can go forward days by clicking the down arrow on the keyboard. 
Each time you do this, the orange checkbox next to the day of the week label will move down to the next day and the timer will restart for the new
day's habit. To complete the habit and stop the timer, press the enter/return key. The checkbox will turn green to indicate being complete and the timer will stop and 
the seconds elapsed will also turn green. 
When you're on a new week and start at Monday again, press fn+delete to clear the previous week's progress. 





