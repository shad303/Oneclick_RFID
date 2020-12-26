const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
	<title> One-Click Shoping Cart  </title>
	<link href="https://fonts.googleapis.com/css?family=Roboto+Condensed" rel="stylesheet">
	<link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta.2/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="custom.css">
</head>
<style>
.body{
	background-color: #f0f0f5;
}
.Product-img img{
	width: 100% ;
}
.main-section{
	font-family: 'Roboto Condensed', sans-serif;
	margin-top:100px;
}
</style>
<body>
	<div class="container main-section">
		<div class="row">
			<div class="col-lg-12 pb-2">
				<h4><b>One-Click Shoping Cart</b></h4>
			</div>
			<div class="col-lg-12 pl-3 pt-3">
				<table class="table table-hover border bg-white">
				    <thead>
				      	<tr>
					        <th>Product</th>
					        <th>Price</th>
					        <th style="width:10%;">Quantity</th>
					        <th>Subtotal</th>
					        <th>Action</th>
				      	</tr>
				    </thead>
				    <tbody>
				      	<tr>
					        <td>
					        	<div class="row">
									<div class="col-lg-2 Product-img">
										<img src="v1.jpg" alt="..." class="img-responsive"/>
									</div>
									<div class="col-lg-10">
										<h4 class="nomargin">Iphone 12</h4>
									</div>
								</div>
					        </td>
					        <td>84900 </td>
					        <td class="text-center" id = "quant12">1</td>
							<td id = "subtotal12">84900</td>
					        <td class="actions" data-th="" style="width:10%;">
								<button class="btn btn-info btn-sm"><i class="fa fa-refresh"></i></button>
								<button class="btn btn-danger btn-sm"><i class="fa fa-trash-o"></i></button>								
							</td>
				      	</tr>
				      	<tr>
					        <td>
					        	<div class="row">
									<div class="col-lg-2 Product-img">
										<img src="v2.jpg" alt="..." class="img-responsive"/>
									</div>
									<div class="col-lg-10">
										<h4 class="nomargin">Iphone 6s</h4>
									</div>
								</div>
					        </td>
					        <td> 18900 </td>
					        <td class="text-center" id = "quant6s">1</td>
							<td id = "subtotal6s"> 18900 </td>
					        <td class="actions" data-th="" style="width:10%;">
								<button class="btn btn-info btn-sm"><i class="fa fa-refresh"></i></button>
								<button class="btn btn-danger btn-sm"><i class="fa fa-trash-o"></i></button>								
							</td>
				      	</tr>
				    </tbody>
				    <tfoot>
						<tr>
							<td><a href="#" class="btn btn-warning text-white"><i class="fa fa-angle-left"></i> Continue Shopping</a></td>
							<td colspan="2" class="hidden-xs"></td>
							<td class="hidden-xs text-center" style="width:10%;"><strong>Total : <span id = "total">103800</span></strong></td>
							<td><a href="#" class="btn btn-success btn-block">Checkout <i class="fa fa-angle-right"></i></a></td>
						</tr>
					</tfoot>
				</table>
			</div>
		</div>
	</div>
	<script>
		setInterval(function() {getquantof12();}, 1000); 
		setInterval(function() {getquantof6s();}, 1000);
		setInterval(function() {getsubtotalof12();}, 1000); 
		setInterval(function() {getsubtotalof6s();}, 1000);
		setInterval(function() {gettotal();}, 1000);

	function getquantof12() {
     var xhttp = new XMLHttpRequest();
     xhttp.onreadystatechange = function() {
     if (this.readyState == 4 && this.status == 200) {
       document.getElementById("quant12").innerHTML = this.responseText;
     }
     };
     xhttp.open("GET", "readquant12", true);
     xhttp.send();
    }
	function getquantof6s() {
     var xhttp = new XMLHttpRequest();
     xhttp.onreadystatechange = function() {
     if (this.readyState == 4 && this.status == 200) {
       document.getElementById("quant6s").innerHTML = this.responseText;
     }
     };
     xhttp.open("GET", "readquant6s", true);
     xhttp.send();
    }
	function getsubtotalof12() {
     var xhttp = new XMLHttpRequest();
     xhttp.onreadystatechange = function() {
     if (this.readyState == 4 && this.status == 200) {
       document.getElementById("subtotal12").innerHTML = this.responseText;
     }
     };
     xhttp.open("GET", "readsubtotal12", true);
     xhttp.send();
    }
	function getsubtotalof6s() {
     var xhttp = new XMLHttpRequest();
     xhttp.onreadystatechange = function() {
     if (this.readyState == 4 && this.status == 200) {
       document.getElementById("subtotal6s").innerHTML = this.responseText;
     }
     };
     xhttp.open("GET", "readsubtotal6s", true);
     xhttp.send();
    }
	function gettotal() {
     var xhttp = new XMLHttpRequest();
     xhttp.onreadystatechange = function() {
     if (this.readyState == 4 && this.status == 200) {
       document.getElementById("total").innerHTML = this.responseText;
     }
     };
     xhttp.open("GET", "readtotal", true);
     xhttp.send();
    }
	</script>
</body>
</html>
)=====";
