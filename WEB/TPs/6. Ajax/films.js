function request(url, callback){
   var xhr = new XMLHttpRequest();
   xhr.onreadystatechange = function() {
     if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
         callback(xhr.responseText);
     }
   };
   xhr.open("GET", url, true);
   xhr.send(null);
}

function getSelectedOptionsAsString(select){
   var stringSelected = '';
   for(var i = 0; i < select.options.length; i++){
      var elem = select.options[i];
      if(elem.selected){
         stringSelected+=elem.value+",";
      }
   }
   stringSelected = stringSelected.substring(0, stringSelected.length - 1);
   return stringSelected;
}

function urlBuilder(){
   var url = 'suggest.php?';
   var title = document.getElementById('title').value ;
   if(title != ''){
      url += 'title='+encodeURIComponent(title)+'&';
   }
   var countries = getSelectedOptionsAsString(document.getElementById('country'));
   if( countries != ''){
      url += 'country='+encodeURIComponent(countries)+'&';
   }
   var startDate = document.getElementById('startYear').value;
   if(startDate != ''){
      url += 'start='+encodeURIComponent(startDate)+'&';
   }
   var endDate = document.getElementById('endYear').value;
   if(endDate != ''){
      url += 'end='+encodeURIComponent(endDate)+'&';
   }
   var actors = getSelectedOptionsAsString(document.getElementById('actors'));
   if(actors != ''){
      url += 'actors='+encodeURIComponent(actors)+'&';
   }
   return url.substring(0,url.length-1);
}

function display(data){
   console.log(data);
   document.getElementById('infopane').innerHTML = data;
}


function getData(){
   console.log(urlBuilder());
   request(urlBuilder(),display);
}


function getActors(data){
   document.getElementById("actors").innerHTML = data;
}

function getCountries(data){
   document.getElementById("country").innerHTML = data;
}

function reset(){
   document.getElementById('infopane').innerHTML = "";
}




function init(){
   request('suggest.php?init=1&getActors=1',getActors);
   request('suggest.php?init=1&getCountries=1', getCountries);
}


document.onload = init();