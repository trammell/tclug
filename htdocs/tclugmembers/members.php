<?php
/*
  If php complains about includes or the formatting looks funky
  Change the $path var to reflect your full path to your members
  directory.  (Not Web Path, but system Path)
*/
$path = "$DOCUMENT_ROOT/tclugmembers";
$vars = str_replace($SCRIPT_NAME, "", $REQUEST_URI);

$array = explode("/",$vars);
$num = count($array); // How many items in the array?
for ($i = 1 ; $i < $num ; $i++) {
    $url_array[$i] = $array[$i];
}

$mode=$url_array[1];
$mid=$url_array[2];
$show=$url_array[2];
$url_pagenum=$url_array[3];

if (!isset($mode) || $mode == ''){$mode = "list";}

require( "$path/include/shared.inc.php");
include("$path/include/lib.inc.php");

if ($mode ==  "list") {
require( "$path/include/members/members_list.inc"); }

elseif ($mode ==  "edit"){
require( "$path/include/members/auth.inc");
require( "$path/include/members/members_edit.inc"); }

elseif ($mode ==  "edited"){
require( "$path/include/members/auth.inc");
require( "$path/include/members/members_edited.inc"); }

elseif ($mode ==  "submit"){
require( "$path/include/members/members_submit.inc"); }

elseif ($mode ==  "submitted"){
require( "$path/include/members/members_submitted.inc"); }

elseif ($mode = 'zoom' && $mid >= "1"){
require( "$path/include/members/members_id.inc");

} else {  echo "Error!"; }

?>
