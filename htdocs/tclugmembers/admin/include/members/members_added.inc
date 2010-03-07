<?
#$bio = eregi_replace("'","\'",$bio);
#$bio = eregi_replace("\"","\\\"",$bio);
MYSQL_CONNECT($hostname, $db_user, $db_pass) OR DIE("Unable to connect to database");
@mysql_select_db( "$dbName") or die( "Unable to select database");
$insert = "insert into $memberstable values('$artnr','$name','$bio','$status','$email','$url','$date','$active','$login','$mempass')";
print "<br>";
$result = MYSQL_QUERY($insert);
$query = "SELECT * FROM $memberstable WHERE(artnr=$artnr)";
$insert = MYSQL_QUERY($query);
$artnr = mysql_insert_id();
print "\"$name\" $has_been_entered $artnr.<br> with the following info";
print "<br>";
print "<br>";
print "\"$login\"";
print "<br>";
print "\"$mempass\"";
print "<br>";
$i++;
print "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"2; URL=$path_to_admin/$membersadmin_script\">";
?>
