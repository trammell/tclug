<?
/*
This is the function library for the MyNews backend
In it I will document each of the functions and explain
a general use of these functions so you can incorporate	
these functions into your website with little to no design
limitations					
*/
					
/*
Author:		Mike McMurray <alien@alienated.org>
Package:	MyNews 2.9.1pre
*/

/*******************************************************************/

function mynews_connect($hostname , $db_user , $db_pass , $dbName){
/*
Quite possibly the most crucial function in this library.
This function establishes the connection to the database
to allow for the other function to perform their queries.

Ex:     mynews_connect(localhost , root , YeahRight , news)
*/
mysql_connect($hostname, $db_user, $db_pass) OR DIE("Unable to connect to database");
mysql_select_db( "$dbName") or die( "Unable to select database");
} //End mynews_connect()

/*******************************************************************/
?>
