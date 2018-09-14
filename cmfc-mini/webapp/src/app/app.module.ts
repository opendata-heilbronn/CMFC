import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppComponent } from './app.component';
import { RobotComponent } from './robot/robot.component';
import { ControlsComponent } from './controls/controls.component';
import { MeterComponent } from './components/meter/meter.component';

@NgModule({
  declarations: [
    AppComponent,
    RobotComponent,
    ControlsComponent,
    MeterComponent
  ],
  imports: [
    BrowserModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
