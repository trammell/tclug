<?
if ($newpass == ""){
$mempass = $oldpass;
} else {
$mempass = $newpass;
  } // End If
#$bio = eregi_replace("'","\'",$bio);
#$bio = eregi_replace("\"","\\\"",$bio);
$insert = "replace into $memberstable values('$mid','$name','$bio','$status','$email','$url','$date','$active','$user','$mempass','$showemail')";
$result = MYSQL_QUERY($insert);
$query = "REPLACE * FROM $memberstable WHERE user=\"$PHP_AUTH_USER\"";
$insert = MYSQL_QUERY($query);
?>
<META HTTP-EQUIV="Refresh" CONTENT="2; URL=<?php echo "$path_to_members_index/$members_script/"; ?>">
<HTML>
<HEAD>
<TITLE><?php echo "$sitename Updated : " . stripslashes($name); ?></TITLE>
<style type="text/css">
<!--
<?php include("$path/include/css.php"); ?>
//--> 
</style>
</HEAD>
<BODY bgcolor="<?php echo "$bg_color"; ?>" text="<?php echo "$text_color"; ?>">
<p>
<b><?php echo stripslashes($name); ?></b> has been updated as user
number: <b><?php echo "$mid"; ?></b>.
</BODY>
</HTML>

