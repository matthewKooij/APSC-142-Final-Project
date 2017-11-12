/*
	142 - Final Project
	Stac-E's Adventure
	M. Kooij && C. Gant
	March 2017
*/

//= INTRO ============================================================================================================================================

/* INTRO JINGLE - CARTER
Now this is a story all about how
A robo-life got turned upside down
And I'd like to take a minute
Just sit right there
I'll tell you how it became the world's fastest processor
*/

// [TURN ON EV3]

/*
MATTHEW
This is the story about a chipper Robot named Stac-E. The year is 2800, and humanity has left Earth due to the environment's devastating state.
The silly humans who'd caused this mess left tons of robots behind;

CARTER
(suspenseful voice) Stac-E was the last bot remaining.
*/

//= CONSTANTS ========================================================================================================================================

#define V 50	// define volume level (50/100)

//= PROTOTYPES =======================================================================================================================================

int inputWait(int time);
int jobTune();
void obstacleCourse();
void plotIcon();
void supriseTone();
void ruffianReaction();
void celebration();


//= MAIN =============================================================================================================================================

task main()
{
	// setup left and right bumpers respectively
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S4] = sensorEV3_Touch;

	// set color sensor and mode
	SensorType[S2] = sensorEV3_Color;
	SensorMode[S2] = modeEV3Color_Color;
	
	// setup ultrasonic sensor
	SensorType[S3] = sensorEV3_Ultrasonic;
	
//------------------------------------------------------------------------------------------------------------------------------------------------
	
	/*
	CARTER
	What kind of job does Stac-E have?
	*/

	// display and cycle through options and instructions && check bumpers for user input
	while (true)
	{
		// text cycle part 1/4
		displayTextLine(2,"What kind of job do I have?");
		displayTextLine(4,"Press left bumper for Maintenance Bot");

		// if input detected, break out of while loop
		if (inputWait(2000) == true)
			break;

		// text cycle part 2/4
		displayTextLine(2,"What kind of job do I have?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) == true)
			break;

		// text cycle part 3/4
		displayTextLine(2,"What kind of job do I have?");
		displayTextLine(4,"Press right bumper for RoboClown");

		// if input detected, break out of while loop
		if (inputWait(2000) == true)
			break;

		// text cycle part 4/4
		displayTextLine(2,"What kind of job do I have?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) == true)
			break;
	}
	
	// make appropriate sound for job selection
	jobTune();
	
//------------------------------------------------------------------------------------------------------------------------------------------------
	
	/*
	MATTHEW
	Every day, Stac-E goes about her robo-job doing her robo-tasks. The distant future of
	Kingston has the city split into aisles; Stac-E has been assigned to the aisle-C.

	CARTER
	On a beautiful, radioactive morning, Stac-E gets to work while avoiding obstacles along the way.
	*/

	// Robot moves, avoiding obstacles using distance sensor
	obstacleCourse();
	
//------------------------------------------------------------------------------------------------------------------------------------------------

	// 7-second pause for narration and/or repositioning
	wait1Msec(7000);
	
	/*
	CARTER
	One day, two purple robo-ruffians show up in Stac-E's territory!
	*/

	// drive forward until color is detected, then stop and react
	while (true)
	{
		// define a variable to store the measured colour code
		int colorSensor;

		// check color sensor
		colorSensor = getColorName(S2);

		// no color detected
		if (colorSensor != colorBlue)
		{
			// drive forward
			motor[motorB] = 30;
			motor[motorC] = 30;
			wait1Msec(250);
		}
		
		// color detected
		else
		{
			// stop
			motor[motorB] = 0;
			motor[motorC] = 0;
			wait1Msec(200);

			// display '!'
			plotIcon();

			// play tone
			supriseTone();
			
			// exit while loop
			break;
		}
		// refresh rate of 100 ms
		wait1Msec(100);
	}

//------------------------------------------------------------------------------------------------------------------------------------------------
	
	/*
	MATTHEW
	This goes against the mandate of the state?s Queen, Mother Aphra, thus Stac-E must intervene.
	How will she proceed? Peacefully or aggressively?
	*/

	// display and cycle through options and instructions && check bumpers for user input
	while (true)
	{
		// text cycle part 1/4
		displayTextLine(2,"How should I proceed?");
		displayTextLine(4,"Press left bumper for Peaceful");

		// if input detected, break out of while loop
		if (inputWait(2000) == true)
			break;

		// text cycle part 2/4
		displayTextLine(2,"How should I proceed?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) == true)
			break;

		// text cycle part 3/4
		displayTextLine(2,"How should I proceed?");
		displayTextLine(4,"Press right bumper for Aggressive");

		// if input detected, break out of while loop
		if (inputWait(2000) == true)
			break;

		// text cycle part 4/4
		displayTextLine(2,"How should I proceed?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) == true)
			break;
	}

	// Robot reacts appropriately
	ruffianReaction();

//------------------------------------------------------------------------------------------------------------------------------------------------
	
	/*
	CARTER
	Peaceful : Stac-E successfully dances the ruffians into friendship and agreement.
	Aggressive : The impressive RPM's of Stac-E's motors intimidate and flummox the ruffians away.

	MATTHEW
	Her Majesty Aphra notices Stac-E?s brave and unabashed courage! To reward her, Stac-E is presented with two choices.
	She may choose to become part of a global supercomputer or she can have upgraded parts.
	*/

	// display and cycle through options and instructions && check bumpers for user input
	while (true)
	{
		// text cycle part 1/4
		displayTextLine(2,"Which reward should I choose?");
		displayTextLine(4,"Press left bumper for Super Computer");

		// if input detected, break out of while loop
		if (inputWait(2000) == true)
			break;

		// text cycle part 2/4
		displayTextLine(2,"Which reward should I choose?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) == true)
			break;

		// text cycle part 3/4
		displayTextLine(2,"Which reward should I choose?");
		displayTextLine(4,"Press right bumper for Upgraded Parts");

		// if input detected, break out of while loop
		if (inputWait(2000) == true)
			break;

		// text cycle part 4/4
		displayTextLine(2,"Which reward should I choose?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) == true)
			break;
	}

	// Stac-E celebrates
	celebration();
}

//= FUNCTIONS ========================================================================================================================================

// Imput Wait: This function checks bumpers for user input every 0.1 seconds and returns i if i < time.
//			   If no input is detected, i = time and textline cycles.
int inputWait(int time)
{
	int i, leftBump, rightBump;
	time /= 100;

	// Runs a for loop 'time/100' times. Ex: if time input is 2000 milliseconds, the loop runs 20 times. Thus, bumper check frequency is 10 Hz.
	for (i=0; i<time; i++)
	{
			// check bumpers
			leftBump = getTouchValue(S1);
			rightBump = getTouchValue(S4);

			// if a bumper is pressed, break out for loop
			if (leftBump == 1 || rightBump == 1)
				break;

			// wait time allows bumper check every 0.1 seconds
			wait1Msec(100);
	}
	return (i < time);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

// Job Tune: This function displays text and plays a tune according to user input && returns a value for 'job'.
int jobTune()
{
	// define return variable
	int job;
	int leftBump;
	int rightBump;

	// check bumpers for user input
	leftBump = getTouchValue(S1);

	// if Maintenance Bot was selected, display selection for 3 seconds then play windows xp tune
	if (leftBump == 1)
	{
		job = 0;
		displayTextLine(4,"Maintenance Bot!");
		wait1Msec(3000);
		
		// volume
		setSoundVolume(V);
		
		// windows xp boot tune
		playTone(622.25,45); 
		wait1Msec(450); 
		playTone(466.16,45); 
		wait1Msec(450);
		playTone(415.30,45); 
		wait1Msec(450);   
		playTone(622.25,24); 
		wait1Msec(240);  
		playTone(466.16,60);
		wait1Msec(250);
		
	}
	
	// if RoboClown was selected, display selection for 3 seconds then play circus tune
	else
	{
		job = 1;
		displayTextLine(4,"RoboClown!");
		wait1Msec(3000);
		
		// volume
		setSoundVolume(V);
		
		// circus tune
		playTone(1104, 23); wait1Msec(75);
		playTone(1054, 23); wait1Msec(75);
		playTone(987, 12); wait1Msec(75);
		playTone(1054, 12); wait1Msec(75);
		playTone(987, 12); wait1Msec(75);
		playTone(929, 12); wait1Msec(75);
		playTone(877, 23); wait1Msec(75);
		playTone(830, 23); wait1Msec(75);
		playTone(788, 23); wait1Msec(75);
		playTone(830, 23); wait1Msec(75);
	}
	return job;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

// Obstacle Course: This function instructs the robot to drive forward while checking the distance sensor.
// 					If the distance is 20 cm or less, the robot will turn 90 degrees left.
void obstacleCourse()
{
	// counter used to end function after 2x left turns
	int distance, i = 0;
	while (i < 2)
	{
		// get distance measurement
		distance = getUSDistance(S3);

		// check if distance is greater than desired
		if (distance > 20)
		{
			// drive forward
			motor[motorB] = 30;
			motor[motorC] = 30;
		}
		else
		{
			// stop
			motor[motorB] = 0;
			motor[motorC] = 0;
			wait1Msec(100);

			// turn left
			motor[motorB] = 30;
			motor[motorC] = -30;
			wait1Msec(580);

			// stop
			motor[motorB] = 0;
			motor[motorC] = 0;
			wait1Msec(100);

			// increase counter
			i++;
		}
		// refresh rate of 100 ms
		wait1Msec(100);
	}
}

//----------------------------------------------------------------------------------------------------------------------

// Plot Icon: This function displays an exclamation mark on the LCD.
void plotIcon()
{
	// variables
	int xOffset = 77, yOffset = 52, x, y;

	// exclamation mark icon
	char icon[21][5] =  {{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	0,0,0,0,0},
						{	0,0,0,0,0},
						{	0,0,0,0,0},
						{	0,0,0,0,0},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},
						{	1,1,1,1,1},};
	
	// nested for-loop to display each pixel
	for (y=0; y<21; y++)
	{
		for (x=0; x<5; x++)
		{
			if (icon[y][x] == 1)
				setPixel(x + xOffset, yOffset + 21-y);
		}
	}
	wait1Msec(250);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

// Surprise Tone: This function plays a surprised sounding tone, similar to a telephone ring.
void supriseTone()
{
	// volume
	setSoundVolume(V);
	
	// tone
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);  // Note(D#, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);  // Note(D#, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);  // Note(D#, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);  // Note(D#, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);   // Note(D, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);  // Note(D#, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);  // Note(D#, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);  // Note(D#, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(933,7); wait1Msec(75);  // Note(D#, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
	playTone(1175,7); wait1Msec(75);  // Note(D, Duration(32th))
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

// Ruffian Reaction: According to user imput, the robot will execute appropriate movements and LED lighting.
void ruffianReaction()
{
	// variables
	int leftBump;
	int rightBump;

	// check left bumper
	leftBump = getTouchValue(S1);

	// for 'Peaceful'
	if (leftBump == 1)
	{
		int i;

		// pulse green
		setLEDColor(ledGreenPulse);

		// slow, round movements x3
		for (i = 1; i < 4; i++)
		{
			// back...
			setMotorSpeed(motorB,8);
			setMotorSpeed(motorC,-8);
			wait1Msec(1200);

			// ...and forth
			setMotorSpeed(motorB,-8);
			setMotorSpeed(motorC,8);
			wait1Msec(1200);
		}
	}

	// for 'Aggressive'
	else
	{
		int i;

		// flash red
		setLEDColor(ledRedFlash);

		// strong, sharp movements x3
		for (i=1; i < 4; i++)
		{
			// back...
			setMotorSpeed(motorB,40);
			setMotorSpeed(motorC,-40);
			wait1Msec(500);

			// ...and forth
			setMotorSpeed(motorB,-40);
			setMotorSpeed(motorC,40);
			wait1Msec(500);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

// Celebration: According to user imput, the robot will execute appropriate movements and sounds.
void celebration()
{
	int superComp;
	
	// check left bumper
	superComp = getTouchValue(S1);

	if (superComp == 1)
	{
		int z;
		
		// pitch raise with while loop
		for (z=0; z<100; z+=2)
		{
			setSoundVolume(z);
			playTone(880+z,4);
			wait1Msec(50);
		}
		
		// sound effect
		setSoundVolume(V);
		playTone(980,100);
		wait1Msec(2000);
		playTone(440,25);
		playTone(880,25);
		playTone(220,25);
		playTone(440,100);
		
		// what does the scouter say about her processor speed?
		displayTextLine(8,">9000!!!");
		wait1Msec(10000);
	}
	else
	{
		// pokémon upgrade sound
		setSoundVolume(V);
		playTone(622.25,45);
		wait1Msec(450);
		playTone(466.16,45);
		wait1Msec(450);
		playTone(415.30,45);
		wait1Msec(450);
		playTone(622.25,24);
		wait1Msec(240);
		playTone(466.16,30);
		
		// level up!
		displayTextLine(8,"1 up!");
		wait1Msec(10000);
	}
}