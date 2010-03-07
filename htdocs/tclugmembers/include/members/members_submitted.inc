<?
if (!$name || !$email || !$user) {

$TITLE = "$sitename : Error!";
include ("$head");
if (!$name) {
	$name = "<B>- Missing -</B>";
}

if (!$email) {
	$email = "<B>- Missing -</B>";
}

print ("
		<p>
	");
print "<TABLE WIDTH=\"85%\">\n";
print "	<TR>\n";
print "	   <TD>\n";
print "<B>ERROR!</B>\n";
print "<p>\n";
print "All fields are required for submission.  Please use the link below and try again.\n";
print "<BR><BR>\n";
print "<A HREF=\"$path_to_members_index/$members_script/submit/\">Please try again</A>.\n";
print "<BR><BR>\n";
print "The information you submitted:\n";
print "<BR><BR>\n";
print "	<UL>\n";
print "	   <LI>Name: $name</LI>\n";
print "	   <LI>E-mail Address: $email</LI>\n";
print "	   <LI>Display Email: $showemail</LI>\n";
print "	   <LI>URL: $url</LI>\n";
print "	   <LI>Bio: <p>$bio</LI>\n";
print "	</UL>";
print "	   </TD>";
print "	</TR>";
print "</TABLE>";

include ("$foot");
die;

} elseif (!ereg('^[-!#$%&\'*+\\./0-9=?A-Z^_`a-z{|}~]+'.'@'.'[-!#$%&\'*+\\/0-9=?A-Z^_`a-z{|}~]+\.'.'[-!#$%&\'*+\\./0-9=?A-Z^_`a-z{|}~]+$',$email)) {

$TITLE = "$sitename : Error!";
include ("$head");
if (!$email) {
	$email = "<B>- Missing -</B>";
}


print "<TABLE class=border WIDTH=\"100%\">\n";
print "	<TR>\n";
print "	   <TD>\n";
print "<B>ERROR!</B>\n";
print "<p>\n";
print "You must enter a valid e-mail address.  Please use the link below and try again.\n";
print "<BR><BR>\n";
print "<A HREF=\"$path_to_members_index/$members_script/submit/\">Please try again</A>.\n";
print "<BR><BR>\n";
print "The information you submitted:\n";
print "<BR><BR>\n";
print "	<UL>\n";
print "	   <LI>Name: $name</LI>\n";
print "	   <LI>E-mail Address: $email</LI>\n";
print "	   <LI>Display E-mail Address: $showemail</LI>\n";
print "	   <LI>URL: $url</LI>\n";
print "	   <LI>Bio: <p>$bio</LI>\n";
print "	</UL>";
print "	   </TD>";
print "	</TR>";
print "</TABLE>";

include("$foot");
 die;

} else {

$pieces = explode(" ", $name);
$first = strtolower("$pieces[0]");
$last = strtolower("$pieces[1]");
if ($last == "") {

$TITLE = "$sitename : Error!";
include ("$head");

print "<TABLE class=border WIDTH=\"100%\">\n";
print "	<TR>\n";
print "	   <TD>\n";
print "<B>ERROR!</B>\n";
print "<p>\n";
print "Please provide your full name, first and last.  Use the link below and try again.\n";
print "<BR><BR>\n";
print "<A HREF=\"$path_to_members_index/$members_script/submit/\">Please try again</A>.\n";
print "<BR><BR>\n";
print "The information you submitted:\n";
print "<BR><BR>\n";
print "	<UL>\n";
print "	   <LI>Name: $name</LI>\n";
print "	   <LI>E-mail Address: $email</LI>\n";
print "	   <LI>Dispaly E-mail Address: $showemail</LI>\n";
print "	   <LI>URL: $url</LI>\n";
print "	   <LI>Bio: <p>$bio</LI>\n";
print "	</UL>";
print "	   </TD>";
print "	</TR>";
print "</TABLE>";


} else {

$first = $first{0};
#$login = "$first$last"; 
$login = "$user"; 

$TITLE = "$sitename : Sweet!  it worked!";
include ("$head");

#$bio = eregi_replace("'","\'",$bio);
#$bio = eregi_replace("\"","\\\"",$bio);
#$name = eregi_replace("'","\'",$name);
#$name = eregi_replace("\"","\\\"",$name);

MYSQL_CONNECT($hostname, $db_user, $db_pass) OR DIE("Unable to connect to database");
@mysql_select_db( "$dbName") or die( "Unable to select database");
$insert = "insert into $mem_subtable values('$artnr','$name','$bio','Member','$email','$url','$date','Yes','$login','','$showemail')";

mail("$mem_subemail", "$mem_subject", "$mem_mailstuff\n$artnr\n$name\n$bio\n$email\n$url\n$date\n$login\n$showemail",
     "From: $adminemail\nX-Mailer: PHP/" . phpversion());

print "<br>";
$result = MYSQL_QUERY($insert);
$query = "SELECT * FROM $mem_subtable WHERE(artnr=$artnr)";
$insert = MYSQL_QUERY($query);
$artnr = mysql_insert_id();
print "\n	<P class=posted>\n";
print "<B>$name</B> has been entered as Submission ID=$artnr<br>\n";
print "		<br>\n";
print "Posted on $date\n";
print "<br>\n";
print "	<BLOCKQUOTE>\n";
print "	<p>\n";
print "<b>Name:</b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$name\n";
print "<br />\n";
print "<b>Email:</b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$email\n";
$i++;
	}
}
require("$foot");
?>
