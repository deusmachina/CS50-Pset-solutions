<?php
    require("../includes/config.php");
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $rows = CS50::query("SELECT symbol FROM portfolio WHERE user_id=?",$_SESSION["id"]);
        if(count($rows) == 0)
            apologize("No stocks to sell. ");
        render("list.php",["title" => "Sell", "list" => $rows]);
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $n = CS50::query("SELECT shares FROM portfolio WHERE user_id=? AND symbol = ?",$_SESSION["id"],$_POST["symbol"]);
        $p = lookup($_POST["symbol"]);
        $ans = $n[0]["shares"]*$p["price"];
        CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?" ,$_SESSION["id"],$_POST["symbol"]);
        CS50::query("INSERT INTO history (transaction, symbol, shares, price, user_id) VALUES ('SELL',?,?,?,?)", $_POST["symbol"], $n[0]["shares"], "$".(string)$ans, $_SESSION["id"]);
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $ans , $_SESSION["id"]);
        redirect("/");
    }
?>