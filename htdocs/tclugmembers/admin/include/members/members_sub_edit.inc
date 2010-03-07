<?

function return_password ($pw_length) { 
     // set ASCII range for random character generation 
     $lower_ascii_bound = 50;          // "2" 
     $upper_ascii_bound = 122;       // "z" 
                                                 
     // Exclude special characters and some confusing alphanumerics 
     // o,O,0,I,1,l etc 
     $notuse = array (58,59,60,61,62,63,64,73,79,91,92,93,94,95,96,108,111); 

     while ($i < $pw_length) { 
          mt_srand ((double)microtime() * 1000000); 
          // random limits within ASCII table 
          $randnum = mt_rand ($lower_ascii_bound, $upper_ascii_bound); 
          if (!in_array ($randnum, $notuse)) { 
          $password = $password . chr($randnum); 
          $i++; 
          } 
     } 
  return $password; 
 }  // End return_password()


$news_query = mysql_query("select * from $mem_subtable where artnr=\"$msid\"") or die(mysql_error());
 
while ($row  =  mysql_fetch_array($news_query))
   {
        $artnr=$row["artnr"];
        $name=$row["name"];
        $bio=$row["bio"];
        $status=$row["status"];
        $email=$row["email"];
        $showemail=$row["showemail"];
        $url=$row["url"];
        $date=$row["date"];
        $active=$row["active"];
        $login=$row["user"];
        	$mempass=return_password(8);
		$TITLE = "$sitename Admin : Submit : $title";
   }

include("$head");
 
include("$adminpath/include/login_check.inc"); 

print ("
<p>
<b>Add Member Submission</b><br>
<a href=\"$path_to_admin/$membersadmin_script\">$back_to_admin</a>
<table width=85%>
<form action=\"$path_to_admin/$membersadmin_script?mode=members_sub_added\" method=\"post\">

   <TR>
	<td valign=top align=right>
<p>
Name:
	</td>
	<td>
<input class=textbox type=\"text\" name=\"name\" size=\"40\" value=\"$name\">
	</td>
   </TR>

   <TR>
	<td valign=top align=right>
<p>
Bio:
	</td>
	<td>
<TEXTAREA class=textbox NAME=\"bio\" COLS=55 ROWS=5 WRAP=PHYSICAL>
$bio
</TEXTAREA>
	</td>
   </TR>

   <TR>
	<td valign=top align=right>
<p>
URL:
	</td>
	<td>
<input class=textbox type=\"text\" name=\"url\" size=\"40\" value=\"$url\">
	</td>
   </TR>

   <TR>
	<td valign=top align=right>
<p>
Email:
	</td>
	<td>
<input class=textbox type=\"text\" name=\"email\" size=\"40\" value=\"$email\">
	</td>
   </TR>

  <TR>
        <td valign=top align=right>
<p>
Display Email:
        </td>
        <td>
<SELECT class=textbox NAME=\"showemail\"><OPTION>$showemail<OPTION>Yes<OPTION>No</SELECT>
        </td>
   </TR>


   <TR>
	<td valign=top align=right>
<p>
Status:
	</td>
	<td>
<SELECT class=textbox NAME=\"status\"><OPTION>Member<OPTION>Secretary<OPTION>Vice-President<OPTION>President</SELECT>
	</td>
   </TR>

   <TR>
	<td valign=top align=right>
<p>
Active:
	</td>
	<td>
<SELECT class=textbox NAME=\"active\"><OPTION>Yes<OPTION>No</SELECT>
	</td>
   </TR>

   <TR>
	<td valign=top align=right>
<p>
User:
	</td>
	<td>
<input class=textbox type=\"text\" name=\"login\" size=\"40\" value=\"$login\">
	</td>
   </TR>

   <TR>
	<td valign=top align=right>
<p>
Password:
	</td>
	<td>
<input class=textbox type=\"text\" name=\"mempass\" size=\"40\" value=\"$mempass\">
	</td>
   </TR>

   <TR>
	<td valign=top align=right>
<input type=\"hidden\" name=\"date\" value=\"$date\">
	</td>
	<td>
$button
	</td>
   </TR>


</table>

</form>
<blockquote>
<i>Today is $nicedate</i>
</blockquote>
	");
include("$foot");
?>
