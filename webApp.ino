String pgForm() {
  return"<!DOCTYPE html><html><head> <title>Pingo Pongo</title> <style> /*! CSS Used from: https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css */*,::after,::before{box-sizing:border-box;}body{margin:0;font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',Roboto,'Helvetica Neue',Arial,sans-serif,'Apple Color Emoji','Segoe UI Emoji','Segoe UI Symbol';font-size:1rem;font-weight:400;line-height:1.5;color:#212529;text-align:left;background-color:#fff;}h3,h4,h6{margin-top:0;margin-bottom:.5rem;}a{color:#007bff;text-decoration:none;background-color:transparent;-webkit-text-decoration-skip:objects;}a:hover{color:#0056b3;text-decoration:underline;}label{display:inline-block;margin-bottom:.5rem;}input,select{margin:0;font-family:inherit;font-size:inherit;line-height:inherit;}input{overflow:visible;}select{text-transform:none;}[type=submit]{-webkit-appearance:button;}[type=submit]::-moz-focus-inner{padding:0;border-style:none;}input[type=checkbox]{box-sizing:border-box;padding:0;}h3,h4,h6{margin-bottom:.5rem;font-family:inherit;font-weight:500;line-height:1.2;color:inherit;}h3{font-size:1.75rem;}h4{font-size:1.5rem;}h6{font-size:1rem;}.container{width:100%;padding-right:15px;padding-left:15px;margin-right:auto;margin-left:auto;}@media (min-width:576px){.container{max-width:540px;}}@media (min-width:768px){.container{max-width:720px;}}@media (min-width:992px){.container{max-width:960px;}}@media (min-width:1200px){.container{max-width:1140px;}}.row{display:-webkit-box;display:-ms-flexbox;display:flex;-ms-flex-wrap:wrap;flex-wrap:wrap;margin-right:-15px;margin-left:-15px;}.col{position:relative;width:100%;min-height:1px;padding-right:15px;padding-left:15px;}.col{-ms-flex-preferred-size:0;flex-basis:0;-webkit-box-flex:1;-ms-flex-positive:1;flex-grow:1;max-width:100%;}.form-control{display:block;width:100%;padding:.375rem .75rem;font-size:1rem;line-height:1.5;color:#495057;background-color:#fff;background-clip:padding-box;border:1px solid #ced4da;border-radius:.25rem;transition:border-color .15s ease-in-out,box-shadow .15s ease-in-out;}.form-control::-ms-expand{background-color:transparent;border:0;}.form-control:focus{color:#495057;background-color:#fff;border-color:#80bdff;outline:0;box-shadow:0 0 0 .2rem rgba(0,123,255,.25);}.form-control::-webkit-input-placeholder{color:#6c757d;opacity:1;}.form-control::-moz-placeholder{color:#6c757d;opacity:1;}.form-control:-ms-input-placeholder{color:#6c757d;opacity:1;}.form-control::-ms-input-placeholder{color:#6c757d;opacity:1;}.form-control::placeholder{color:#6c757d;opacity:1;}.form-control:disabled{background-color:#e9ecef;opacity:1;}select.form-control:not([size]):not([multiple]){height:calc(2.25rem + 2px);}.form-group{margin-bottom:1rem;}.form-check-input{position:absolute;margin-top:.3rem;margin-left:-1.25rem;}.form-check-input:disabled~.form-check-label{color:#6c757d;}.form-check-label{margin-bottom:0;}.btn{display:inline-block;font-weight:400;text-align:center;white-space:nowrap;vertical-align:middle;-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none;border:1px solid transparent;padding:.375rem .75rem;font-size:1rem;line-height:1.5;border-radius:.25rem;transition:color .15s ease-in-out,background-color .15s ease-in-out,border-color .15s ease-in-out,box-shadow .15s ease-in-out;}.btn:focus,.btn:hover{text-decoration:none;}.btn:focus{outline:0;box-shadow:0 0 0 .2rem rgba(0,123,255,.25);}.btn:disabled{opacity:.65;}.btn-outline-primary{color:#007bff;background-color:transparent;background-image:none;border-color:#007bff;}.btn-outline-primary:hover{color:#fff;background-color:#007bff;border-color:#007bff;}.btn-outline-primary:focus{box-shadow:0 0 0 .2rem rgba(0,123,255,.5);}.btn-outline-primary:disabled{color:#007bff;background-color:transparent;}.btn-outline-info{color:#17a2b8;background-color:transparent;background-image:none;border-color:#17a2b8;}.btn-outline-info:hover{color:#fff;background-color:#17a2b8;border-color:#17a2b8;}.btn-outline-info:focus{box-shadow:0 0 0 .2rem rgba(23,162,184,.5);}.btn-outline-info:disabled{color:#17a2b8;background-color:transparent;}.text-muted{color:#6c757d!important;}@media print{*,::after,::before{text-shadow:none!important;box-shadow:none!important;}h3{orphans:3;widows:3;}h3{page-break-after:avoid;}body{min-width:992px!important;}.container{min-width:992px!important;}} </style></head><body> <div class='container'> <form action='/conf' method='get'> <div class='form-group'> <div class='row'> <div class='col'> <h3>Benvenuto nella pagina iniziale! <br> inserisci le tue informazioni</h3><br> </div>  </div> <label class='text-muted' for='Nome:'> </label> <input class='form-control' id='Nome' name='Nome' placeholder='il nome che verrà visualizzato:'><br><input class='form-control' id='Email' name='Email' placeholder='la tua Email:'><br><input class='form-control' id='Password' name='Password' placeholder='la tua password:'><br><input type='submit' class='btn btn-outline-primary' value='Invia tutto!'> </form> <br> </div></body></html>";
}


void handle_conf() {
  Serial.println("Qualcuno mi ha fatto una richiesta.../n");
  partizioni[n_partizioni].nome = server.arg("Nome");
  partizioni[n_partizioni].email = server.arg("Email");
  partizioni[n_partizioni].password = server.arg("Password");
  Serial.print("nome:");
  Serial.print(partizioni[n_partizioni].nome);
  Serial.print(" Email:");
  Serial.print(partizioni[n_partizioni].email);
  Serial.print("Password:");
  Serial.print(partizioni[n_partizioni].password);

  server.send(200, "text/html", "<meta http-equiv='refresh' content='1; URL=/' >");
}

void handle_form() {

  server.send(200, "text/html", pgForm());
}
