import { Component, OnInit } from '@angular/core';
import * as $ from 'jquery';

@Component({
	selector: 'app-robot',
	templateUrl: './robot.component.html',
	styleUrls: ['./robot.component.css']
})
export class RobotComponent implements OnInit {

	constructor() { }

	ngOnInit() {
		$(".meter > span").each(function () {
			$(this)
				.data("origWidth", $(this).width())
				.width(0)
				.animate({
					width: $(this).data("origWidth")
				}, 1200);
		});
	}

}
