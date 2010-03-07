<?
$bio = eregi_replace("'","\'",$bio);
$bio = eregi_replace("\"","\\\"",$bio);
$cryptpass = crypt($newpass, 'lI');
mynews_connect($hostname , $db_user , $db_pass , $dbName);
$insert = "insert into $authorstable values('$artnr','$name','$bio','$status','$email','$url','$date','$active','$login','$cryptpass','','','')";
print "<br>";
$result = MYSQL_QUERY($insert);
$query = "SELECT * FROM $authorstable WHERE(artnr=$artnr)";
$insert = MYSQL_QUERY($query);
$artnr = mysql_insert_id();
?>

<META HTTP-EQUIV="Refresh" CONTENT="2; URL=<?php echo "$path_to_admin/$authadmin_script"; ?>">
<HTML>
<HEAD>
<TITLE><?php echo "$sitename Admin : Added : " . stripslashes($login); ?></TITLE>
<style type="text/css">
<!--
<?php include("$path/include/css.php"); ?>
//-->
</style>
</HEAD>
<BODY bgcolor="<?php echo "$bg_color"; ?>" text="<?php echo "$text_color"; ?>">
<p>
<b><?php echo stripslashes($name); ?></b> has been added
as: 
<blockquote>
<p>
<b>User:</b> <?php echo "$login"; ?>
<br>
<b>Pass:</b> <?php echo "$newpass"; ?>
</BODY>
</HTML>
