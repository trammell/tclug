<?
 
$news_query = mysql_query("select * from $authorstable where user=\"$PHP_AUTH_USER\"") or die(mysql_error());
 
while ($row  =  mysql_fetch_array($news_query))
   {
        $record_number=$row["artnr"];
        $name=$row["name"];
        $bio=$row["bio"];
        $status=$row["status"];
        $email=$row["email"];
        $url=$row["url"];
        $date=$row["date"];
        $active=$row["active"];
        $user=$row["user"];
        $oldpass=$row["password"];
        $listening=$row["listening"];
        $reading=$row["reading"];
        $thinking=$row["thinking"];
		$TITLE = "$sitename Admin : Preferences";
   }

include("$head");
include("$adminpath/include/login_check.inc"); 
print ("
		<p>
		<b>Edit User Info:</b><br>
		<a href=\"$path_to_admin/\">Go back to admin</a>

<TABLE WIDTH=100% CELLPADDING=2 CELLSPACING=2 BORDER=0>
   <form action=\"$path_to_admin/$prefsadmin_script?mode=change_prefs&item=$record_number\" method=\"post\">
	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>Name:</b>
	   </td>
	   <td VALIGN=TOP>
	<input class=textbox type=\"text\" name=\"name\" size=\"40\" value=\"$name\">
	   </td>
	</tr>
	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>Bio:</b>
  <br>
<i>(Optional)</i>
	   </td>
	   <td VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"bio\" COLS=70 ROWS=10 WRAP=VIRTUAL>$bio</TEXTAREA>
	   </td>
	</tr>

	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>Hearing:</b>
  <br>
<i>(Optional)</i>
	   </td>
	   <td VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"listening\" COLS=70 ROWS=5 WRAP=VIRTUAL>$listening</TEXTAREA>
	   </td>
	</tr>

	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>Reading:</b>
  <br>
<i>(Optional)</i>
	   </td>
	   <td VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"reading\" COLS=70 ROWS=5 WRAP=VIRTUAL>$reading</TEXTAREA>
	   </td>
	</tr>

	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>Thinking:</b>
  <br>
<i>(Optional)</i>
	   </td>
	   <td VALIGN=TOP>
	<TEXTAREA class=textbox NAME=\"thinking\" COLS=70 ROWS=5 WRAP=VIRTUAL>$thinking</TEXTAREA>
	   </td>
	</tr>


	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>URL:</b>
	   </td>
	   <td VALIGN=TOP>
	<input class=textbox type=\"text\" name=\"url\" size=\"40\" value=\"$url\"><br>
	   </td>
	</tr>
	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>Email:</b>
	   </td>
	   <td VALIGN=TOP>
	<input class=textbox type=\"text\" name=\"email\" value=\"$email\" size=\"40\"><br>
	   </td>
	</tr>

	<tr>
	  <td>
		&nbsp;
	  </td>
	  <td>
		<p>
		Enter Password twice to change it.
		  <br>
		Leave the next two fields blank to keep your current password.
		  <br>
		  <br>
		<b>Warning:</b> you will be prompted to relogin if your password is changed.
	  </td>
	</tr>

	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>Password:</b>
		  <br>
	   </td>
	   <td VALIGN=TOP>
	<input class=textbox type=\"password\" name=\"newpass\">
	   </td>
	</tr>
	<tr>
	   <td ALIGN=Right VALIGN=TOP>
<b>Confirm Password:</b>
	   </td>
	   <td VALIGN=TOP>
	<input class=textbox type=\"password\" name=\"confirmpass\">
	   </td>
	</tr>
	<tr>
	  <td>
	<input type=\"hidden\" name=\"oldpass\" value=\"$oldpass\">
	<input type=\"hidden\" name=\"active\" value=\"Yes\">
	<input type=\"hidden\" name=\"date\" value=\"$date\">
	<input type=\"hidden\" name=\"user\" value=\"$user\">
	<input type=\"hidden\" name=\"status\" value=\"$status\">
	  </td>
	  <td>
	$button
	  </td>
	</tr>
   </table>
  </form>
<blockquote>
	<i>Today is $nicedate</i>
</blockquote>
   ");

include("$foot");
?>
