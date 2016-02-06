<html>

<head>
<meta http-equiv="Content-Language" content="ja">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>残り物管理 Ver.3</title>
</head>

<body>

<?php
require("connection.inc");
require("modulev2.inc");

$DBCONN = DBconnect("ZAIKO");

// 変数の初期設定
//  前のページから引き渡されたものについては、その値を使うが、
//  未設定の場合は初期値を設定する
if(isset($_POST["PAGE"])) {
	$PAGE = $_POST["PAGE"] ;
} else {
	$PAGE = 0 ;
}

// 表示オプション(1)
if(isset($_POST["OPT1"])) {
	$OPT1 = $_POST["OPT1"] ;
} else {
	$OPT1 = 0 ;
}

// 表示オプション(2)
if(isset($_POST["OPT2"])) {
	$OPT2 = $_POST["OPT2"] ;
} else {
	$OPT2 = 0 ;
}

// 表示オプション(3)
if(isset($_POST["OPT3"])) {
	$OPT3 = $_POST["OPT3"] ;
} else {
	$OPT3 = 0 ;
}

if(isset($_POST["BTN"])) {
	$BTN = $_POST["BTN"] ;
} else {
	$BTN = "" ;
}

$MAXCOUNT = MAXCOUNT($OPT1, $OPT2);

// print("PAGE:" . $_POST["PAGE"] . "<br>");

// 前のページで実行されたボタンの内容
switch($BTN) {
	case	"前のページ":
		if($_POST["PAGE"] > 10) {
			$PAGE = $_POST["PAGE"]  - 10;
		} else {
			$PAGE = 0;
		}
		include("showtablev2.inc");
		break;

	case	"次のページ":
		if($_POST["PAGE"] + 10 < $MAXCOUNT) {
			$PAGE = $_POST["PAGE"]  + 10;
		} else {
			$PAGE = $_POST["PAGE"];
		}
		include("showtablev2.inc");
		break;

	case	"登録":
		$MESSAGE = RECORD($_POST["ItemName"], $_POST["ItemCount"], $_POST["BuyDate1"], $_POST["BuyDate2"], $_POST["BuyDate3"], $_POST["LimitDate1"], $_POST["LimitDate2"], $_POST["LimitDate3"]);
		if(!is_null($MESSAGE)) {
			print($MESSAGE . "<br>\n");
		}
		include("showtablev2.inc");
		break;

	case	"更新":
		$MESSAGE = MODIFY($_POST["ZAIKO_No"], $_POST["ItemCount"]);
		if(!is_null($MESSAGE)) {
			print($MESSAGE . "<br>\n");
		}
		include("showtablev2.inc");
		break;

	case	"表示オプション":
		include("listoptv2.inc");
		break;

	case	"購入":
		include("recordpagev2.inc");
		break;

	case	"修正":
		include("modifypagev2.inc");
		break;

	case	"表示オプション更新":
		$PAGE = $_POST["PAGE"];
		include("showtablev2.inc");
		break;

	case	"キャンセル":
		include("showtablev2.inc");
		break;

	case	"":
		$PAGE = 0;
		include("showtablev2.inc");
		break;
}

?>

</body>

</html>
