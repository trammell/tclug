<?
$news_query = mysql_query("select * from $memberstable where user=\"$PHP_AUTH_USER\"") or die(mysql_error());
$row  =  mysql_fetch_array($news_query);
        $mid=$row["artnr"];
        $name=$row["name"];
        $bio=stripslashes($row["bio"]);
        $status=$row["status"];
        $email=$row["email"];
        $showemail=$row["showemail"];
        $url=$row["url"];
        $date=$row["date"];
        $active=$row["active"];
        $user=$row["user"];
        $oldpass=$row["password"];

include("$head");
 
print ("
<b>
Edit Member Info:
</b>
<form action=\"$path_to_members_index/$members_script/edited/$mid/\" method=\"post\">
<TABLE WIDTH=100% CELLPADDING=2 CELLSPACING=2 BORDER=0>
	<tr>
	  <td ALIGN=Right VALIGN=TOP WIDTH=150>
<p>
Name:
	  </td>
	  <td WIDTH=475 VALIGN=TOP>
<input class=textbox type=\"text\" name=\"name\" size=\"40\" value=\"$name\">
	  </td>
	</tr>
	<tr>
	  <td ALIGN=Right VALIGN=TOP WIDTH=150>
<p>
Bio:
	  </td>
	  <td WIDTH=475 VALIGN=TOP>
<TEXTAREA class=textbox NAME=\"bio\" COLS=50 ROWS=5 WRAP=PHYSICAL>$bio</TEXTAREA>
	  </td>
	</tr>
	<tr>
	  <td ALIGN=Right VALIGN=TOP WIDTH=150>
<p>
URL:
	  </td>
	  <td WIDTH=475 VALIGN=TOP>
<input class=textbox type=\"text\" name=\"url\" size=\"40\" value=\"$url\"><br>
	  </td>
	</tr>
	<tr>
	  <td ALIGN=Right VALIGN=TOP WIDTH=150>
<p>
Email:
	  </td>
	  <td WIDTH=475 VALIGN=TOP>
<input class=textbox type=\"text\" name=\"email\" value=\"$email\" size=\"40\"><br>
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP WIDTH=150>
<p>
Active:
	  </td>
	  <td WIDTH=475 VALIGN=TOP>
<SELECT class=textbox NAME=\"active\">
  <OPTION>$active
  <OPTION>Yes
  <OPTION>No
</SELECT>
	  </td>
	</tr>


        <tr>
          <td ALIGN=Right VALIGN=TOP WIDTH=150>
<p>
Show Email:
          </td>
          <td WIDTH=475 VALIGN=TOP>
<SELECT class=textbox NAME=\"showemail\">
  <OPTION>$showemail
  <OPTION>Yes
  <OPTION>Converted
  <OPTION>No
</SELECT>
          </td>
        </tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP WIDTH=150>
<b>Note:</b>
	  </td>
	  <td WIDTH=475 VALIGN=TOP>
<p>
You only need to fill in the password field if you are changing your password
	  </td>
	</tr>

	<tr>
	  <td ALIGN=Right VALIGN=TOP WIDTH=150>
<p>
Password:
	  </td>
	  <td WIDTH=475 VALIGN=TOP>
<input class=textbox type=\"password\" name=\"newpass\">
	  </td>
	</tr>
	<tr>
	  <td>
<input type=\"hidden\" name=\"oldpass\" value=\"$oldpass\">
<input type=\"hidden\" name=\"status\" value=\"$status\">
<input type=\"hidden\" name=\"date\" value=\"$datetime\">
<input type=\"hidden\" name=\"user\" value=\"$user\">
	  </td>
	  <td>
		$button
	  </td>
	</tr>
</TABLE>
</form>
<blockquote>
<i>$today_is $nicedate</i>
</blockquote>
   ");

include("$foot");
?>
