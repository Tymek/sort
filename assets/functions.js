function cl(s){console.log(s)};
cl("Rendering DOM…");

$(function () {
	cl("Document ready. Setting variables…");
	
	$.ajaxSetup({async: false});
		
	$checkbox = $(".table input[type=checkbox]");
	
	var allData = [];
	
	var dataType = ["random", "sorted", "reverse", "exceptions"];
	var dataLabel = ["Dane losowe"
		,"Dane posortowane"
		,"Dane posortowane odwrotnie"
		,"Dane posortowane z wyjątkami"
	];
	
	var algorithm = ["coctail"
		,"selection"
		, "insertion"
		, "quick"
		, "heap",
		"shell"
	];
	
	var algorithmLabel = ["Sortowanie koktailowe"
		, "Sortowanie przez wybór"
		, "Sortowanie przez wstawianie"
		, "Sortowanie szybkie"
		, "Sortowanie stogowe"
		, "Sortowanie Shella"
	];
	
	var colors = ['#CC333F'
		, '#EDC951','#EB6841', '#1A9481', '#00A0B0', '#215A6D'
	];
	
	cl("Loading chart plugin…");
	$.getScript("assets/highcharts/highcharts.js");
	$.getScript("assets/highcharts/modules/exporting.js");
	$.getScript("assets/theme.js");
	
	
	cl("Setting HighCharts options…");
	Highcharts.setOptions({
		lang: {
			decimalPoint: ",",
			numericSymbols: [ "k" , "M" , "G" , "T" , "P" , "E"],
			loading: "Ładowanie…",
			contextButtonTitle: "Menu kontekstowe",
			downloadJPEG: "Pobierz JPEG", 
			downloadPDF: "Pobierz PDF", 
			downloadPNG: "Pobierz PNG", 
			downloadSVG: "Pobierz SVG",
			printChart: "Wydrukuj wykres",
			resetZoom: "Domyślne przybliżenie",
			resetZoomTitle: "Ustala skalę na 1:1",
			thousandsSep: " "
		}
	});
	
	
	cl("Initializing HighCharts…");
	$('#container').highcharts({
		chart: {
			zoomType: 'x',
			type: "spline"
		},
		title: {
			text: 'Porównanie wydajności algorytmów sortujących'
		},
		subtitle: {
			text: document.ontouchstart === undefined ?
				'Kliknij i przesuń myszą aby powiększyć' :
				'Uszczypnij wykres aby powiększyć'
		},
		xAxis: {
			title: {
				text: 'Ilość danych'
			},
			type: 'logarithmic',
		},
		yAxis: {
			title: {
				text: 'Czas w sekundach'
			},
			min: 0/*,
			max: 600
			*/
		},
		//colors: ['#8E2800', '#B64926', '#FFB03B', '#9BCC93', '#1A9481', '#003D5C', '#FFF0A5', '#000000', '#000000', '#000000'],
		colors:['#CC333F', '#EDC951','#EB6841',
				'#1A9481', '#00A0B0', '#215A6D'],
		
		legend: {
			enabled: false
		},
		tooltip: {
			valueSuffix: 's',
			valueDecimals: 2
		},
   
		series: [{id: null}
				,{id: null}
				,{id: null}
				,{id: null}
				,{id: null}
				,{id: null}
		]
	});
	var chart = $('#container').highcharts();
	
	cl("Loading data…");
	for(var a = 0; a<algorithm.length; a++){
		var series = [];
		for(var d = 0; d<dataType.length; d++){
			var query = "data/"
				+ dataType[d]
				+ "/"+algorithm[a]
				+ ".sort.json"
				+ "?dataType=" + d // Cache fix
			;
			$.getJSON(query
				, function(data){
					series.push(data);
				}
			);
		}
		allData.push(series);
	}
	
	cl("Setting functions…");
	function setSeries(a, d, target){
		var options = {
			id: "d"+d+"a"+a,
			name: algorithmLabel[a]+" / "+dataLabel[d],
			data: allData[a][d]
		};
		chart.series[target].update(options);
		chart.series[target].show();
		
		setColor(a, d, target);
	}
	
	function removeSeries(a, d){
		s = chart.get("d"+d+"a"+a);
		if(s === null) return;
		s = chart.series[s.index];
		s.setVisible(false);
		s.update({id:null});
		
		setColor(a, d, null);
	}
	
	function setColor(a, d, color){
		if(color === null) color = "transparent";
		else color = colors[color];
		$checkbox.filter("[name=d"+d+"a"+a+"]").parent()
			.css("background", color);
	}
	
	function simulateClick(a, d){
		$(".table input[type=checkbox]")
			.filter("[name=d"+d+"a"+a+"]")
			.click();
	}
	
	function wipe(){
		$checkbox.each(function(){
			$(this).prop("checked", false)
			.parent().css("background", "transparent");
		});
		chart.series.forEach(function(s){
			s.setVisible(false);
			s.update({id:null});			
		});
		
	}
	
	cl("Binding events…");
	$checkbox.change(function(e){
		var a = $(this).prop("name").charAt(3);
		var d = $(this).prop("name").charAt(1);
		if($(this).prop("checked")){
			var i,
			id;
			for(i=0; i<algorithm.length; i++){
				id = chart.series[i].options.id;
				if(id === null) break;
			}
			if(i<algorithm.length){
				setSeries(a, d, i);
			} else {
				/*simulateClick(a, d);*/
				e.preventDefault();
				$(this).prop("checked", false);
			}
		} else {
			removeSeries(a, d);
		}
	});
	
	$("th").click(function(){
		//cl($(this));
		var $e = $(this);
		var d = $e.data("type");
		if(d !== undefined && d !== null){
			wipe();
			for(var i = 0; i<algorithm.length; i++){
				simulateClick(i, d);
			}
		} else {
			var a = $e.data("algorithm");
			if(a !== undefined && a !== null){
				wipe();
				for(var i = 0; i<dataType.length; i++){
					simulateClick(a, i);
				}
			}
		}
	});
	
	$("button[data-switch=scale]").click(function(e){
		e.preventDefault;
		$("button[data-switch=scale]").removeAttr("disabled");
		$(this).attr("disabled", true);
		chart.xAxis[0].update({type: $(this).attr("data-value")});
	});
	
});

$(window).load(function(){
	cl("Window loaded. Preparing initial chart series…");
	for(var i=0; i<3; i++){
		$(".table input[type=checkbox]")
		.filter("[name=d"+0+"a"+i+"]")
		.click();
	}
	cl("Removing loading animation…");
	$("#container").css("background", "transparent");
	cl("AAAnd it's gone!");
});

/* STRZĘPKI POPRZEDNIEJ WERSJI - zostawione gdyby jakaś część kodu się przydała
	
	$("#da input[name=algo]").change(function(){
		setAlgo($("input[name=algo]:checked").attr("data-id"));
	});
	*/
	/*
	$('#scale').change(function() {
		if($(this).is(":checked")){
			chart.xAxis[0].update({type: 'logarithmic'});
		} else {
			chart.xAxis[0].update({type: 'linear'});
		}
	});*/
	/*
	
	$("button[data-switch=comp]").click(function(e){
		e.preventDefault;
		$("button[data-switch=comp]").removeAttr("disabled");
		$(this).attr("disabled", true);
		if($(this).attr("data-value")=="dt"){
			$(".alg").fadeOut(function(){
				$(".dt").fadeIn();
			});
			for(var i = 0; i < 6; i++){
				chart.series[i].hide();
			}
			chart.series[0].update({name: "Losowe dane"});
			if($("#random2").is(":checked")) chart.series[0].show();
			
		} else {
			$(".dt").fadeOut(function(){
				$(".alg").fadeIn();
				
				chart.series[0].update({name: "Sortowanie koktailowe"});
			});
		}
		//chart.xAxis[0].update({type: $(this).attr("data-value")});
	});*/
	/*
	$('#aa input[type=checkbox]').change(function(){
		var $e = $(this);
		if($e.closest("tr").hasClass("groupToggle")){
			$("input[data-group="+ $e.attr("name") +"]").each(function(){
				if($e.is(":checked")){
					$(this).prop("checked", true);
					chart.series[$(this).attr("data-id")].show();
				} else {
					$(this).prop("checked", false);
					chart.series[$(this).attr("data-id")].hide();
				}
			});
		} else {
			if($e.is(":checked")){
				chart.series[$e.attr("data-id")].show();
			} else {
				chart.series[$e.attr("data-id")].hide();
			}
			var type;
			var q=0;
			$("input[data-group="+$e.attr("data-group")+"]").each(function(){
				if($(this).is(":checked")) q++;
			});
			if(q==0){
				$("input[name="+$e.attr("data-group")+"]").prop("checked", false);
			} else {
				$("input[name="+$e.attr("data-group")+"]").prop("checked", true);
			}
			
		}
	});*//*
for(var i=0; i<6; i++){
	$(".table input[type=checkbox]")
	.filter("[name=d"+0+"a"+i+"]")
	.click();
}
*/