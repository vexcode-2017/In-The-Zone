//Replay data include

#if ZERO_OUT_AUTON
    #include "AutonomousReplayData_ZERO.h";
    #include "ProgrammingReplayData_ZERO.h";
    #warn "TURN OFF ZERO_OUT_AUTON"
#else
    #include "AutonomousReplayData.h";
    #include "ProgrammingReplayData.h";
#endif

const int _f_ch3 = 0;
const int _f_ch4 = 1;
const int _f_btn = 2;
const byte _mask_b5u = 1;
const byte _mask_b5d = 2;
const byte _mask_b6u = 4;
const byte _mask_b6d = 8;
const byte _mask_b8u = 16;
const byte _mask_b8d = 32;

byte _bch1 = 0;
byte _bch2 = 0;
byte bch3 = 0;
byte bch4 = 0;
bool b5u = false;
bool b5d = false;
bool b6u = false;
bool b6d = false;
bool _b7u = false;
bool _b7d = false;
bool _b7l = false;
bool _b7r = false;
bool b8u = false;
bool b8d = false;
bool _b8l = false;
bool _b8r = false;

task ReplayReader(){
	writeDebugStreamLine("(%s,%d): Entering ReplayReader task ",__FILE__,__LINE__);
	int a = 0;
	if(pinRunAutonomous()){
		int modifier = pinReverseAutonomousChModifier();
		while(true){
			if(bIfiAutonomousMode && a < 750){
				//bch1 = f_auton_ch[a][_f_ch1] * modifier;
				//bch2 = f_auton_ch[a][_f_ch2];
				bch3 = f_auton_ch[a][_f_ch3];
				bch4 = f_auton_ch[a][_f_ch4] * modifier;
				b5u = (bool) (f_auton_ch[a][_f_btn] & _mask_b5u);
				b5d = (bool) (f_auton_ch[a][_f_btn] & _mask_b5d);
				b6u = (bool) (f_auton_ch[a][_f_btn] & _mask_b6u);
				b6d = (bool) (f_auton_ch[a][_f_btn] & _mask_b6d);
				//b7u = f_auton_btn[a][_f_b7u];
				//b7d = f_auton_btn[a][_f_b7d];
				//b7l = f_auton_btn[a][_f_b7l];
				//b7r = f_auton_btn[a][_f_b7r];
				b8u = (bool) (f_auton_ch[a][_f_btn] & _mask_b8u);
				b8d = (bool) (f_auton_ch[a][_f_btn] & _mask_b8d);
				//b8l = f_auton_btn[a][_f_b8l];
				//b8r = f_auton_btn[a][_f_b8r];
				a++;
				sleep(20);
			}else{
				_bch1 = vexRT[Ch1];
				_bch2 = vexRT[Ch2];
				bch3 = vexRT[Ch3];
				bch4 = vexRT[Ch4];
				b5u = (bool) vexRT[Btn5U];
				b5d = (bool) vexRT[Btn5D];
				b6u = (bool) vexRT[Btn6U];
				b6d = (bool) vexRT[Btn6D];
				_b7u = (bool) vexRT[Btn7U];
				_b7d = (bool) vexRT[Btn7D];
				_b7l = (bool) vexRT[Btn7L];
				_b7r = (bool) vexRT[Btn7R];
				b8u = (bool) vexRT[Btn8U];
				b8d = (bool) vexRT[Btn8D];
				_b8l = (bool) vexRT[Btn8L];
				_b8r = (bool) vexRT[Btn8R];
				a++;
				sleep(10);
			}
		}
	}else if(pinRunProgrammingSkills()){
		while(a < 3000){
			bch3 = f_prog_ch[a][_f_ch3];
			bch4 = f_prog_ch[a][_f_ch4];
			b5u = (bool) (f_prog_ch[a][_f_btn] & _mask_b5u);
			b5d = (bool) (f_prog_ch[a][_f_btn] & _mask_b5d);
			b6u = (bool) (f_prog_ch[a][_f_btn] & _mask_b6u);
			b6d = (bool) (f_prog_ch[a][_f_btn] & _mask_b6d);
			b8u = (bool) (f_prog_ch[a][_f_btn] & _mask_b8u);
			b8d = (bool) (f_prog_ch[a][_f_btn] & _mask_b8d);
			a++;
			sleep(20);
		}
	}else if(!bIfiAutonomousMode){
		while(true){
			_bch1 = vexRT[Ch1];
			_bch2 = vexRT[Ch2];
			bch3 = vexRT[Ch3];
			bch4 = vexRT[Ch4];
			b5u = (bool) vexRT[Btn5U];
			b5d = (bool) vexRT[Btn5D];
			b6u = (bool) vexRT[Btn6U];
			b6d = (bool) vexRT[Btn6D];
			_b7u = (bool) vexRT[Btn7U];
			_b7d = (bool) vexRT[Btn7D];
			_b7l = (bool) vexRT[Btn7L];
			_b7r = (bool) vexRT[Btn7R];
			b8u = (bool) vexRT[Btn8U];
			b8d = (bool) vexRT[Btn8D];
			_b8l = (bool) vexRT[Btn8L];
			_b8r = (bool) vexRT[Btn8R];
			a++;
			sleep(10);
		}
	}
}
