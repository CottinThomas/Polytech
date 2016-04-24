$(document).ready(function(){

	var init = function(){
		$('.menu_content').hide();
	}

	$('.menu_title').on('click', function(){
		var $item = $(this).parent().children('.menu_content');
		$(this).children('.icone').toggleClass('plus');
		$(this).children('.icone').toggleClass('moins');
		$item.slideToggle();
		$item.parent().toggleClass('openedItem');
		if($(this).parent().hasClass('animated')) {
			$(this).animate({fontSize:'3em'});
			$(this).animate({fontSize:'1.2em'});
		}
	});

	init();

});