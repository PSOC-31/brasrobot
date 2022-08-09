#include<Arduino.h>
#include "BrasRobot.h"


//@constructeur
void BrasRobot::init()
{
activerMoteurs();
	initPosition();

}
BrasRobot::BrasRobot()
{
//	init();
ralenti=10;
}


void BrasRobot::setRalenti(int v)
{

ralenti=v;
}

void BrasRobot::setAnglesBECP(int b, int e, int c, int p)
{ 
	int j=0;
	Serial.print("b:");
	Serial.print(b);
	Serial.print("\te:");
	Serial.print(e);
	Serial.print("\tc:");
	Serial.print(c);
	Serial.print("\tp:");
	Serial.println(p);
	
		for (int i=0;i<180;i++)
		{
			j=180-i;
			Serial.print("base:");
			Serial.print(abase);
			Serial.print("\tepaule:");
			Serial.print(aepaule);
			Serial.print("\tcoude:");
			Serial.print(acoude);
			Serial.print("\tpoignet:");
			Serial.print(apoignet);
			Serial.print("\ti:");
			Serial.print(i);
			Serial.print("\tj:");
			Serial.println(j);
			
			b=(b+180)%180;
			e=(e+180)%180;
			c=(c+180)%180;
			p=(p+180)%180;
			
			
			if(b>abase)
			{
				if (i>abase && i<b)	abase++;
			}
			else{
				if (j<abase && j>b) abase--;	
			}
			
			if(e>aepaule)
			{
				if (i>aepaule && i<e)	aepaule++;
					
			}
			else{
				if (j<aepaule && j>e) aepaule--;	
			}
			
			if (c>acoude)
			{
				if (i>acoude && i<c)	acoude++;

			}
			else{
				if (j<acoude && j>c) acoude--;					
			}
			
			if (p>apoignet)
			{
				if (i>apoignet && i<p)	apoignet++;
			}
			else{
				if (j<apoignet && j>p) apoignet--;					
			}
			
			sbase.write(abase);
			sepaule1.write(aepaule);
			sepaule2.write(inv(aepaule));
			scoude.write(acoude);		
			spoignet.write(apoignet);
			delay(ralenti);
		}
	
	
}

void BrasRobot::updatePos()
{
/*	sepaule1.write(aepaule);
	sepaule2.write(aepaule);
	scoude.write(acoude);
	spoignet.write(apoignet);
	spince.write(apince);
*/
}
void BrasRobot::activerMoteurs()
{
	spince.attach(pinpince);
	spoignet.attach(pinpoignet);
	scoude.attach(pincoude);
	sepaule1.attach(pinepaule1);
	sepaule2.attach(pinepaule2);
	sbase.attach(pinbase);	
	pinMode(pinbouton,INPUT_PULLUP);
	while (digitalRead(pinbouton)==HIGH)
	{}
}

void BrasRobot::desactiverMoteurs()
{
	spince.detach();
	spoignet.detach();
	scoude.detach();
	sepaule1.detach();
	sepaule2.detach();
	sbase.detach();	
	
	
}
int BrasRobot::inv(int val)
{
	return 180-val;
}

//@Articulations
void BrasRobot::setAnglePince(int angle)  
{
	if (angle >-1 && angle <181)
	{
	if (apince<angle)
	{
		while(apince<angle)
		{
			apince++;
			spince.write(apince);
			delay(ralenti);
		}
	}
	else
	{
		while (apince>angle)
		{
			apince--;
			spince.write(apince);
			delay(ralenti);
		}	
	}
	}
 }
 
void BrasRobot::setAnglePoignet(int angle)
{
	if (angle >-1 && angle <181)
	{
	if (apoignet<angle)
	{
		while(apoignet<angle)
		{
			apoignet++;
			spoignet.write(apoignet);
			delay(ralenti);
		}
	}
	else
	{
		while (apoignet>angle)
		{
			apoignet--;
			spoignet.write(apoignet);
			delay(ralenti);
		}	
	}
	}
}

void BrasRobot::setAngleCoude(int angle)  
{
	if (angle >-1 && angle <181)
	{
	if (acoude<angle)
	{
		while(acoude<angle)
		{
			acoude++;
			scoude.write(acoude);
			delay(ralenti);
		}
	}
	else
	{
		while (acoude>angle)
		{
			acoude--;
			scoude.write(acoude);
			delay(ralenti);
		}	
	}
	}
}
	
void BrasRobot::setAngleEpaule(int angle) 
{
	if (angle >-1 && angle <181)
	{
	if (aepaule<angle)
	{
		while(aepaule<angle)
		{
			aepaule++;
			sepaule1.write(aepaule);
			sepaule2.write(inv(aepaule));
			delay(ralenti);
		}
	}
	else
	{
		while (aepaule>angle)
		{
			aepaule--;
			sepaule1.write(aepaule);
			sepaule2.write(inv(aepaule));
			delay(ralenti);
		}	
	}
	}
}

void BrasRobot::setAngleBase(int angle)   
{
	if (abase<angle)
	{
		while(abase<angle)
		{
			abase++;
			sbase.write(abase);
			delay(ralenti);
		}
	}
	else
	{
		while (abase>angle)
		{
			abase--;
			sbase.write(abase);
			delay(ralenti);
		}	
	}
}

void BrasRobot::finTravail()
{
	
	delay(2000);
	int tt=ralenti;
	ralenti=1;
	for (int i=0;i<3;i++)
	{
	fermerPince();
	ouvrirPince();
	}
	ralenti=tt;
	initPosition();
	//setAnglesBECP(90, 100,60,60);
	desactiverMoteurs();

	while (1)
	{	desactiverMoteurs();
}

}

//@mouvements basiques
void BrasRobot::lever()
{
		setAnglesBECP(abase, 45,0,135);

}

void BrasRobot::baisser()
{
	setAnglesBECP(abase, 135,0,45);

}

void BrasRobot::rotationGauche()
{
	setAngleBase(0);
}
void BrasRobot::rotationDroite()
{
		setAngleBase(180);

}

void BrasRobot::rotationMilieu()
{
		setAngleBase(0);

}

void BrasRobot::initPosition()
{
	setAnglesBECP(90, 90,90,90);


}

//@pince

void BrasRobot::ouvrirPince()
{
		while(apince<130)
		{
			apince++;
			spince.write(apince);
			delay(ralenti);
		}
}

void BrasRobot::fermerPince()
{
		while(apince>60)
		{
			apince--;
			spince.write(apince);
			delay(ralenti);
		}

}

void BrasRobot::inclinerHaut()	{	setAnglePoignet(160);}

void BrasRobot::inclinerBas()	{	setAnglePoignet(20);}

void BrasRobot::horizontal()
{
	int vv=0;
	if (aepaule+acoude<180)
	vv=180-aepaule-acoude;
else
	vv=360-aepaule-acoude;
setAnglePoignet(vv);


}




