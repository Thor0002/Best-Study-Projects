This program implements work with a database,  
which stores pairs of the form: date, event.  
The database allows you to work in real time.  
Date as a Year-Month-Day string, where Year, Month, and Day are integers.  
It supports the following commands:  
1) Add date event - add a pair (date, event) to the database.  
2) Print - display the entire contents of the database.  
3) Find condition - display all records contained in the database that satisfy the condition.  
4) Del condition - delete all records from the database that meet the condition condition.  
5) Last date - displays a record with the last event that occurred no later than this date.  

Conditions in the Find and Del commands impose certain restrictions on dates and events, such as:  
 - Find date < 2017-11-06 - find all events that happened before November 6, 2017;  
 - Del event! = "holiday" - remove all events from the database, except for "holiday";  
 - Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event" - find all "sport event" events that occurred in the first half of 2017;  
 - Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event") - remove from the database all "holiday" and "sport event" events that occurred before 2017.  
In both types of commands, conditions can be empty: all events fall under this condition.  

Examples:  
1.  
Input:  
 Add 2017-06-01 1st of June  
 Add 2017-07-08 8th of July  
 Add 2017-07-08 Someone's birthday  
 Del date == 2017-07-08  
Output:  
 Removed 2 entries  
2.  
Input:  
 Add 2017-01-01 Holiday  
 Add 2017-03-08 Holiday  
 Add 2017-1-1 New Year  
 Add 2017-1-1 New Year  
 Print  
Output:  
 2017-01-01 Holiday  
 2017-01-01 New Year  
 2017-03-08 Holiday  
3.  
Input:  
 Add 2017-01-01 Holiday  
 Add 2017-03-08 Holiday  
 Add 2017-01-01 New Year  
 Find event != "working day"  
 Add 2017-05-09 Holiday  
Output:  
 2017-01-01 Holiday  
 2017-01-01 New Year  
 2017-03-08 Holiday  
 Found 3 entries  
4.  
Input:  
 Add 2017-01-01 New Year  
 Add 2017-03-08 Holiday  
 Add 2017-01-01 Holiday  
 Last 2016-12-31  
 Last 2017-01-01  
 Last 2017-06-01  
 Add 2017-05-09 Holiday  
Output:  
 No entries  
 2017-01-01 Holiday  
 2017-03-08 Holiday  
5.  
Input:  
 Add 2017-11-21 Tuesday  
 Add 2017-11-20 Monday  
 Add 2017-11-21 Weekly meeting  
 Print  
 Find event != "Weekly meeting"  
 Last 2017-11-30  
 Del date > 2017-11-20  
 Last 2017-11-30  
 Last 2017-11-01  
Output:  
 2017-11-20 Monday  
 2017-11-21 Tuesday  
 2017-11-21 Weekly meeting  
 2017-11-20 Monday  
 2017-11-21 Tuesday  
 Found 2 entries  
 2017-11-21 Weekly meeting  
 Removed 2 entries  
 2017-11-20 Monday  
 No entries  
