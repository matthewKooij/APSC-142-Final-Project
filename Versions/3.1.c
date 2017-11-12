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
I'll tell you how it became the world’s fastest processor
*/

// [TURN ON EV3]

/*
MATTHEW
This is the story about a chipper Robot named Stac-E. The year is 2800, and humanity has left Earth due to the environment’s devastating state.
The silly humans who'd caused this mess left tons of robots behind;

CARTER
(suspenseful voice) Stac-E was the last bot remaining.
*/

//= VARIABLES ========================================================================================================================================

int leftBump;
int rightBump;
int superComp;

//= PROTOTYPES =======================================================================================================================================

int inputWait(int time);
int jobTune();
void obstacleCourse();
void ruffianReaction();
void celebration();
//void plotIcon(bool icon);

//= MAIN =============================================================================================================================================

task main()
{

//= SENSORS ==========================================================================================================================================

	// setup left and right bumpers respectively
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S4] = sensorEV3_Ultrasonic;

	// setup ultrasonic sensor
	SensorType[S3] = sensorEV3_Ultrasonic;

	// set color sensor and mode
	SensorType[S2] = sensorEV3_Color;
	SensorMode[S2] = modeEV3Color_Color;
	
//====================================================================================================================================================

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
		if (inputWait(2000) < 20)
			break;

		// text cycle part 2/4
		displayTextLine(2,"What kind of job do I have?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) < 20)
			break;

		// text cycle part 3/4
		displayTextLine(2,"What kind of job do I have?");
		displayTextLine(4,"Press right bumper for RoboClown");

		// if input detected, break out of while loop
		if (inputWait(2000) < 20)
			break;

		// text cycle part 4/4
		displayTextLine(2,"What kind of job do I have?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) < 20)
			break;
	}

	jobTune();

	/*
	MATTHEW
	Every day, Stac-E goes about her robo-job doing her robo-tasks. The distant future of
	Kingston has the city split into aisles; Stac-E has been assigned to the aisle-C.

	CARTER
	On a beautiful, radioactive morning, Stac-E gets to work while avoiding obstacles along the way.
	*/

	// Robot moves, avoiding obstacles using distance sensor
	obstacleCourse();

	// while [beeps a tune] || [beeps a tune comically], driving in a straight line towards coloured surface. Meanwhile, someone narrates...

	/*
	CARTER
	One day, two purple robo-ruffians show up in Stac-E’s territory!
	*/

	while (true)
	{
		// define a variable to store the measured colour code
		int colorSensor;
		
		// check color sensor
		colorSensor = getColorName(S2);

		//
		if (colorSensor == 0)
		{
			// drive forward
			motor[motorB] = 30;
			motor[motorC] = 30;
			wait1Msec(250);
		}
		else
		{
			// stop
			motor[motorB] = 0;
			motor[motorC] = 0;
			wait1Msec(200);

			// display '!'

			// play tone

			break;
		}
		// refresh rate of 100 ms
		wait1Msec(100);
	}
	
	
	char icon[24][24] =
	{	{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0},
		{	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0},
		{	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0},
		{	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0},
		{	0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},};

	//plotIcon(icon);

	int xOffset = 77;
	int yOffset = 52;
	int q;
	int r;

	for (q=0; q<24; q++)
	{
		for (r = 0; r<24; r++)
		{
			if (icon[q][r] == 1)
				setPixel(r + xOffset,yOffset + 24-q);
		}
	}
	wait1Msec(10000);

	/*
	MATTHEW
	This goes against the mandate of the state’s Queen, Mother Aphra, thus Stac-E must intervene.
	How will she proceed? Peacefully or aggressively?
	*/

	while (true)
	{

		// text cycle part 1/4
		displayTextLine(2,"How should I proceed?");
		displayTextLine(4,"Press left bumper for Peaceful");

		// if input detected, break out of while loop
		if (inputWait(2000) < 20)
			break;

		// text cycle part 2/4
		displayTextLine(2,"How should I proceed?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) < 20)
			break;

		// text cycle part 3/4
		displayTextLine(2,"How should I proceed?");
		displayTextLine(4,"Press right bumper for Aggressive");

		// if input detected, break out of while loop
		if (inputWait(2000) < 20)
			break;

		// text cycle part 4/4
		displayTextLine(2,"How should I proceed?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) < 20)
			break;
	}

	ruffianReaction();

	/*
	CARTER
	Peaceful : Stac-E successfully dances the ruffians into friendship and agreement.
	Aggressive : The impressive RPM's of Stac-E's motors intimidate and flummox the ruffians away.
	*/

	/*
	MATTHEW
	Her Majesty Aphra notices Stac-E’s brave and unabashed courage! To reward her, Stac-E is presented with two choices.
	She may choose to become part of a global supercomputer or she can have upgraded parts.
	*/

	while (true)
	{
		// set counter

		// text cycle part 1/4
		displayTextLine(2,"Which reward should I choose?");
		displayTextLine(4,"Press left bumper for Super Computer");

		// if input detected, break out of while loop
		if (inputWait(2000) < 20)
			break;

		// text cycle part 2/4
		displayTextLine(2,"Which reward should I choose?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) < 20)
			break;

		// text cycle part 3/4
		displayTextLine(2,"Which reward should I choose?");
		displayTextLine(4,"Press right bumper for Upgraded Parts");

		// if input detected, break out of while loop
		if (inputWait(2000) < 20)
			break;

		// text cycle part 4/4
		displayTextLine(2,"Which reward should I choose?");
		displayTextLine(4,"or");

		// if input detected, break out of while loop
		if (inputWait(1000) < 20)
			break;
	}

	// Fuction for ending
	celebration();
}
// Fin.

//= FUNCTIONS ========================================================================================================================================

// Imput Wait: This function checks bumpers for user input every 0.1 seconds. If user imput is detected, true is returned.
int inputWait(int time)
{
	int i;
	time /= 100;

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
	return i;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

// Job Tune: This function displays text and plays a tune according to user input && returns a value for 'job'.
int jobTune()
{
	// define return variable
	int job;

	// check bumpers for user input
	leftBump = getTouchValue(S2);
	rightBump = getTouchValue(S1);

	// if Maintenance Bot was selected, display selection for 4 seconds
	if (leftBump == 1)
	{
		job = 0;
		displayTextLine(4,"Maintenance Bot!");
		wait1Msec(4000);
		//reg tune
	}
	// if RoboClown was selected, display selection for 4 seconds
	else
	{
		job = 1;
		displayTextLine(4,"RoboClown!");
		wait1Msec(4000);
		//comical tune
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
		distance = getUSDistance(S2);

		// check if distance is greater than desired
		if (distance > 20)
		{
			// drive forward
			motor[motorB]=30;
			motor[motorC]=30;
		}
		else
		{
			// stop
			motor[motorB]=0;
			motor[motorC]=0;
			wait1Msec(100);

			// turn left
			motor[motorB]=30;
			motor[motorC]=-30;
			wait1Msec(580);

			// stop
			motor[motorB]=0;
			motor[motorC]=0;

			// increase counter
			i++;
		}
		// refresh rate of 100 ms
		wait1Msec(100);
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

// Ruffian Reaction: According to user imput, the robot will execute appropriate movements and LED lighting.
void ruffianReaction()
{
	// check bumpers
	leftBump = getTouchValue(S2);
	rightBump = getTouchValue(S1);

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
			setMotorSpeed(motorB,10);
			setMotorSpeed(motorC,-10);
			wait1Msec(2000);

			// ...and forth
			setMotorSpeed(motorB,-10);
			setMotorSpeed(motorC,10);
			wait1Msec(2000);
		}
	}

	// for 'Aggressive'
	else
	{
		int i;

		// flash red
		setLEDColor(ledRedFlash);

		// strong, sharp movements x5
		for (i=1; i < 6; i++)
		{
			// back...
			setMotorSpeed(motorB,50);
			setMotorSpeed(motorC,-50);
			wait1Msec(800);

			// ...and forth
			setMotorSpeed(motorB,-50);
			setMotorSpeed(motorC,50);
			wait1Msec(800);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

// Celebration: According to user imput, the robot will execute appropriate movements and sounds.
void celebration()
{
	if (superComp == 1)
		{
			// pitch raise with while loop
			displayTextLine(4,">9000!!!");
		}
	else
		{
			// Pokémon upgrade sound
		}
}

//----------------------------------------------------------------------------------------------------------------------

/*
//Draw: this function allows the Robot to display images on the LCD
void plotIcon(bool icon[q][r])
{
	int xOffset = 77;
	int yOffset = 52;
	int q;
	int r;

	for (q= 0; q<24; q++)
	{
		for (r = 0; r<24; r++)
		{
			if (icon[q][r] == 1)
				setPixel(q + xOffset,yOffset + 24-r);
		}
	}
	wait1Msec(10000);
}
*/
