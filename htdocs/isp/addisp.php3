<?
if ($isp_id) {
	$db = mysql_connect ("ranger.real-time.com", "cfandre", "vgvzp8p2");
	mysql_select_db("wwwmnlinuxorg",$db);
	$table="isp";

	$sql="SELECT * FROM $table where isp_id=$isp_id";

	$result=mysql_query($sql,$db) or die ("Invalid Query");

	$numrows=mysql_num_rows($result);
	if (!$numrows) {
		echo "Sorry. No user with that ID.";
		mysql_close($db);
		exit;
	}
}

if (($isp_id) && (mysql_result($result,0,"password") != $password)) {
	echo "Sorry. Password Invalid.";
	mysql_close($db);
	include("listall.php3");
} elseif ($isp_id) {

$first_name=mysql_result($result,0,"first_name");
$last_name=mysql_result($result,0,"last_name");
$email=mysql_result($result,0,"email");
$age=mysql_result($result,0,"age");
$occupation=mysql_result($result,0,"occupation");
$fav_dist=mysql_result($result,0,"fav_dist");
$started_linux=mysql_result($result,0,"started_linux");
$add_info=mysql_result($result,0,"add_info");
	echo "<H1>Edit ISP Info</H1>";
} else {
	echo "<H1>Add ISP</H1>";
}

echo "<FORM METHOD=POST ACTION=\"submitisp.php3\">";
echo "<TABLE><TR><TD>";
echo "ISP Name*<BR><INPUT TYPE=text NAME=name VALUE=\"$name\">";
echo "</TD></TR><TR><TD>";

echo "Website Address*<BR>";
echo "<INPUT TYPE=text NAME=website VALUE=\"$website\" SIZE=40><BR>";
echo "</TD><TD>";

echo "Occupation<BR>";
echo "<INPUT TYPE=text NAME=occupation VALUE=\"$occupation\" SIZE=30><BR>";
echo "</TD><TD>";

echo "Favorite Distribution<BR>";
echo "<INPUT TYPE=text NAME=fav_dist VALUE=\"$fav_dist\"><BR>";
echo "</TD></TR><TR><TD>";

echo "When did you start using Linux?<BR>";
echo "<INPUT TYPE=text NAME=started_linux VALUE=\"$started_linux\"><BR>";
echo "</TD></TR>";

if (!$password) {
echo "<TR><TD>";
echo "Password*<BR>";
echo "<INPUT TYPE=password NAME=password SIZE=8><BR>";
echo "</TD></TR><TR><TD>";

echo "Confirm Password*<BR>";
echo "<INPUT TYPE=password NAME=password2 SIZE=8><BR>";
echo "</TD></TR>";
}
echo "<TR><TD>";
echo "Any additional information you would like to share";
echo "<TEXTAREA NAME=add_info COLS=\"40\" ROWS=\"5\" WRAP=\"virtual\">$add_info</TEXTAREA><BR>";
if ($isp_id) {
	echo "<INPUT TYPE=hidden NAME=isp_id VALUE=$isp_id>";
	echo "<INPUT TYPE=submit NAME=modify VALUE=\"Modify ISP Info\">";
} else {
	echo "<INPUT TYPE=submit NAME=submit VALUE=\"Submit New ISP Info\">";
}
echo "</TD></TR></TABLE>";
?>
