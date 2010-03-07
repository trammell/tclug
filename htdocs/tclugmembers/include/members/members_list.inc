<?

include("$head");
include("$path/include/members/yahoo.inc");
print "<table width=\"85%\" align=center>";
if (!isset($show) || $show == '') $show=0;
$sql="select * from members";
$result=mysql_query($sql) or die (mysql_error());
$num_members=mysql_numrows($result);
print "There are currently $num_members TCLUG members registered.";
$query = mysql_query("SELECT artnr,name from $memberstable order by name LIMIT $show, $limit") or die (mysql_error());
WHILE ($row = mysql_fetch_array($query)){
         $mid = $row["artnr"];
         $name = $row["name"];

echo row_place($i);
$fullhtml = ("
  <TD width=\"50%\">
<a href=\"$path_to_members_index/$members_script/zoom/$mid/\">$name</a><BR>
</td>
");
print "$fullhtml";
$i++;
   } // End While
print "</tr>";
print "</table>";
include("$path/include/members/members_nav.inc");
include("$foot");
?>
