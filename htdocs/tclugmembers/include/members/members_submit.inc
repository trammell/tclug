<?
$TITLE = "$sitename : Submit an Article";
include("$head");

print ("
<b> Members Submission form </b>
<p>
<table width=85% border=0>
<form action=\"$path_to_members_index/$members_script/submitted/\" method=\"post\">

	<tr>
	  <td valign=top align=right>
<P>Name
	  </td>
	  <td>
<input class=textbox type=\"text\" name=\"name\" size=\"30\">
	  </td>
	</tr>

        <tr>
          <td valign=top align=right>
<P>Username
          </td>
          <td>
<input class=textbox type=\"text\" name=\"user\" size=\"30\">
          </td>
        </tr>

	<tr>
	  <td valign=top align=right>
<P>Bio:
	  </td>
	  <td>
<TEXTAREA class=textbox NAME=\"bio\" COLS=50 ROWS=5></TEXTAREA>
	  </td>
	</tr>

	<tr>
	  <td valign=top align=right>
<P>URL:
	  </td>
	  <td>
<input class=textbox type=\"text\" name=\"url\" size=\"40\"><br>
	  </td>
	</tr>

	<tr>
	  <td valign=top align=right>
<P>Your Email Address
	  </td>
	  <td>
<input class=textbox type=\"text\" name=\"email\" size=\"40\"><br>
	  </td>
	</tr>

        <tr>
          <td valign=top align=right>
<P>Display email on webpage?
          </td>
          <td>
<SELECT class=textbox NAME=\"showemail\">
  <OPTION>Yes
  <OPTION>Converted
  <OPTION>No
</SELECT>
          </td>
        </tr>

	<tr>
	  <td>
<input type=\"hidden\" name=\"date\" value=\"$datetime\">
	  </td>
	  <td>
$button
	  </td>
	</tr>
</table>
</form>
<blockquote>
<i>Today is: $nicedate</i>
</blockquote>
	");
include("$foot");
?>
