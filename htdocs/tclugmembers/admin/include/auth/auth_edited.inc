<?
if (!isset($newpass)){
$newpass = $oldpass;
} else {
$newpass = crypt($newpass, 'lI');
  } // End If
$bio = eregi_replace("'","\'",$bio);
$bio = eregi_replace("\"","\\\"",$bio);
$listening = eregi_replace("'","\'",$listening);
$listening = eregi_replace("\"","\\\"",$listening);
$reading = eregi_replace("'","\'",$reading);
$reading = eregi_replace("\"","\\\"",$reading);
$thinking = eregi_replace("'","\'",$thinking);
$thinking = eregi_replace("\"","\\\"",$thinking);

$insert = "replace into $authorstable values('$item','$name','$bio','$status','$email','$url','$date','$active','$login','$newpass','$listening','$reading','$thinking')";
print "<br>";
$result = MYSQL_QUERY($insert);
$query = "REPLACE * FROM $authorstable WHERE artnr=\"$id\"";
$insert = MYSQL_QUERY($query);
$artnr = mysql_insert_id();
?>
<META HTTP-EQUIV="Refresh" CONTENT="2; URL=<?php echo "$path_to_admin/$authadmin_script"; ?>">
<HTML>
<HEAD>
<TITLE><?php echo "$sitename Admin : Updated : " . stripslashes($name); ?></TITLE>
<style type="text/css">
<!--
<?php include("$path/include/css.php"); ?>
//--> 
</style>
</HEAD>
<BODY bgcolor="<?php echo "$bg_color"; ?>" text="<?php echo "$text_color"; ?>">
<p>
<b><?php echo stripslashes($name); ?></b> has been updated as user 
number: <b><?php echo "$artnr"; ?></b>.
</BODY>
</HTML>

