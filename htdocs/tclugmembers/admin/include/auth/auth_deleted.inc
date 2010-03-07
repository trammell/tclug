<?
$query = mysql_query("SELECT artnr,name from $authorstable where artnr='$id' order by artnr") or die (mysql_error());
$row = mysql_fetch_array($query);
        $artnr = $row["artnr"];
        $delname = $row["name"];

$result = MYSQL_QUERY($insert);
$query = "DELETE FROM $authorstable WHERE(artnr=$id)";
$insert = MYSQL_QUERY($query);
?>

<META HTTP-EQUIV="Refresh" CONTENT="2; URL=<?php echo "$path_to_admin/$authadmin_script?mode=delete_list"; ?>">
<HTML>
<HEAD>
<TITLE><?php echo "$sitename Admin : Deleted : " . stripslashes($name); ?></TITLE>
<style type="text/css">
<!--
<?php include("$path/include/css.php"); ?>
//--> 
</style>
</HEAD>
<BODY bgcolor="<?php echo "$bg_color"; ?>" text="<?php echo "$text_color"; ?>">
<p>
<b><?php echo stripslashes($delname); ?></b> has been deleted as user 
number: <b><?php echo "$id"; ?></b>.
</BODY>
</HTML>
