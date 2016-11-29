<?php
    
    require("../includes/config.php");
    if($_SERVER["REQUEST_METHOD"] == "GET")
        render("change_pass.php" ,[ "title" => "Change Password" ]);
        
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["oldpass"]))
            apologize("You must provide your old password.");
            
        else if(empty($_POST["password"]))
            apologize("You must provide your new password.");
        
        else if(empty($_POST["confirmation"]))
            apologize("You must provide your new password again.");
            
        $row = CS50::query("SELECT * FROM users WHERE id = ?",$_SESSION["id"]);
        
        if(! password_verify($_POST["oldpass"], $row[0]["hash"]))
            apologize("Old password is incorrect. ");

        else if($_POST["password"] != $_POST["confirmation"])
            apologize("Entered passwords do not match. ");
            
        $success = CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["password"], PASSWORD_DEFAULT), $_SESSION["id"]);
        
        if($success == 0)
            apologize("Internal error ");
        redirect("/");
    }
    
?>