<?
#$bio = eregi_replace("'","\'",$bio);
#$bio = eregi_replace("\"","\\\"",$bio);
MYSQL_CONNECT($hostname, $db_user, $db_pass) OR DIE("Unable to connect to database");
@mysql_select_db( "$dbName") or die( "Unable to select database");
$insert = "insert into $memberstable values('','$name','$bio','$status','$email','$url','$date','$active','$login','$mempass','$showemail')";
print "<br>";
$result = MYSQL_QUERY($insert) or die(mysql_error());
$query = "SELECT * FROM $memberstable WHERE(artnr=$artnr)";
$insert = MYSQL_QUERY($query);
$artnr = mysql_insert_id();

$subject = "You Request has been processed";
$thanks = ("
$name,

Thank you for your application to the $sitename member database.
Your Request has been processed and your user info is as follows:

User:	$login
Pass:	$mempass

Please login and change your password and update your info as soon
as possible at the following URL:

$siteurl$path_to_members_index/$members_script/zoom/$artnr/

thanks,
Admin
($adminemail)
");


mail("$email,$adminemail", $subject, $thanks,
	"From: $adminemail\nX-Mailer: PHP/" .phpversion());

print "\"$name\" $has_been_entered $artnr.<br>";
$i++;
print "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"2; URL=$path_to_admin/$membersadmin_script\">";
?>
