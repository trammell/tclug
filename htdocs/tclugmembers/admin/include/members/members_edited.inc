<?
if ($newpass == ""){
$mempass = $oldpass;
} else {
$mempass = $newpass;
  } // End If

#$bio = eregi_replace("'","\'",$bio);
#$bio = eregi_replace("\"","\\\"",$bio);
$insert = "replace into $memberstable values('$mid','$name','$bio','$status','$email','$url','$date','$active','$login','$mempass', '$showemail')";
print "<br>";
$result = MYSQL_QUERY($insert);
$query = "select * FROM $memberstable WHERE artnr=\"$mid\"";
$insert = MYSQL_QUERY($query);
$artnr = mysql_insert_id();
print "\"$name\" has been updated $artnr.<br>";
print "<br>";
$i++;
print "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"2; URL=$path_to_admin/$membersadmin_script\">";
?>
