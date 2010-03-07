<?
 $level_query = mysql_query("select user,status from $authorstable where user='$user'");
 while ($row = mysql_fetch_array($level_query))
     {
         $user=$row["user"];
         $status=$row["status"];
     }
print "<p class=posted>\n";
print "Logged in as $user with status of $status.  &nbsp;&nbsp;&nbsp;";
print "(<A HREF=\"$path_to_admin/$prefsadmin_script\">preferences</A>)";
 
?> 
