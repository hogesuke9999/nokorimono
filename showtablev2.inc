<?php
$SQL  = "select ZAIKO.BuyDate, ZAIKO.LimitDate, ZAIKO.ItemName, ZAIKO.ItemCount, ItemUnitName.ItemUnitName, ZAIKO.ZAIKO_No";
$SQL .= " from ZAIKO, ItemUnitName";
$SQL .= " where ZAIKO.ItemUnitNameCode = ItemUnitName.ItemUnitNameCode";

// 賞味期限による表示・非表示
//  OPT1 = 0 : すべて表示
//  OPT1 = 1 : 賞味期限が切れているものを表示
//  OPT1 = 2 : 賞味期限が切れていないものを表示

switch($OPT1) {
	case	"1":
		$SQL .= " and ZAIKO.LimitDate < current_date";
		break;

	case	"2":
		$SQL .= " and ZAIKO.LimitDate >= current_date";
		break;
}

// 在庫の有無による表示・非表示
//  OPT2 = 0 : すべて表示
//  OPT2 = 1 : 在庫がないものを表示
//  OPT2 = 2 : 在庫があるものを表示
switch($OPT2) {
	case	"1":
		$SQL .= " and ZAIKO.ItemCount <= 0";
		break;

	case	"2":
		$SQL .= " and ZAIKO.ItemCount > 0";
		break;
}

// 表示順の変更
//  OPT3 = 0 : 登録順
//  OPT3 = 1 : 購入日順
//  OPT3 = 2 : 賞味期限順
switch($OPT3) {
	case	"0":
		$SQL .= " order by ZAIKO.Zaiko_No";
		break;

	case	"1":
		$SQL .= " order by ZAIKO.BuyDate";
		break;

	case	"2":
		$SQL .= " order by ZAIKO.LimitDate";
		break;
}
$SQL .= " offset ${PAGE} limit 10";
// print($SQL);
$result = DBexec($SQL);

print("<h1>残り物 一覧</h1>\n");

print("<table border=1>");

print("<tr>\n");
print("<th width=20>No.</th>\n");
print("<th width=100>購入日</th>\n");
print("<th width=100>賞味期限</th>\n");
print("<th width=300>品物名</th>\n");
print("<th width=50>量</th>\n");
print("<th width=50>単位</th>\n");
// print("<th width=100>更新</th>\n");
print("<th width=50>更新</th>\n");
print("</tr>\n");

for ($i = 0 ; $i < pg_numrows($result) ; $i++) {
	print("<tr>\n");
	print("<form method=\"POST\" action=\"index.php\">\n");
	print("<td>" . ($i + 1) . "</td>\n");
	print("<input type=\"hidden\" name=\"ZAIKO_No\" value=\"" . htmlspecialchars(pg_result($result, $i, 5)) . "\">");
	print("<td>" . htmlspecialchars(pg_result($result, $i, 0)) . "</td>\n");
	print("<td>" . htmlspecialchars(pg_result($result, $i, 1)) . "</td>\n");
	print("<td>" . htmlspecialchars(pg_result($result, $i, 2)) . "</td>\n");
	print("<td><input name=\"ItemCount\" type=\"text\" size=\"4\" value=\"" . htmlspecialchars(pg_result($result, $i, 3)) . "\"</td>\n");
	print("<td>" . htmlspecialchars(pg_result($result, $i, 4)) . "</td>\n");
	print("<td><input type=\"submit\" value=\"更新\" name=\"BTN\">");
// 	print("<input type=\"submit\" value=\"修正\" name=\"BTN\"></td>\n");
	print("<input type=\"hidden\" name=\"OPT1\" value=\"${OPT1}\">");
	print("<input type=\"hidden\" name=\"OPT2\" value=\"${OPT2}\">");
	print("<input type=\"hidden\" name=\"OPT3\" value=\"${OPT3}\">");
	print("</form>\n");
	print("</tr>\n");
}

print("</table>");

print("<hr>");

print("<form method=\"POST\" action=\"index.php\">\n");
print("<input type=\"hidden\" name=\"OPT1\" value=\"${OPT1}\">");
print("<input type=\"hidden\" name=\"OPT2\" value=\"${OPT2}\">");
print("<input type=\"hidden\" name=\"OPT3\" value=\"${OPT3}\">");
print("<input type=\"hidden\" name=\"PAGE\" value=\"${PAGE}\">");
print("<input type=\"submit\" name=\"BTN\" value=\"前のページ\">\n");
print("<input type=\"submit\" name=\"BTN\" value=\"次のページ\">\n");
print("<input type=\"submit\" name=\"BTN\" value=\"購入\">\n");
print("<input type=\"submit\" name=\"BTN\" value=\"表示オプション\">\n");
print("</form>\n");

?>
