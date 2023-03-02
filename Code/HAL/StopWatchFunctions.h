/********************			Author: Ahmed Mohamed			***********************/
/********************			Layer: App			 			***********************/
/********************			Component: Stop Watch		    ***********************/
/********************			Version: 1.00		 			***********************/
/********************			Date: 2-3-2023	 				***********************/
/**************************************************************************************/

#ifndef STOPWATCHFUNCTIONS_H_
#define STOPWATCHFUNCTIONS_H_

/* Function to reset the stopWatch to restart the stopWatch to begin from 0 again */
void Reset_StopWatch (void);

/*  * [Description]:  Function to stop the stopWatch to freeze on the value which stopped at */
void Stop_stopWatch(void);

/* Function to force the stopWatch to work from the final value it stopped at */
void Resume_StopWatch(void);

/* Function to increment the a variable which act as an interrupt occur */
void Detect_Seconds(void);


#endif
