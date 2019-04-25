/*****************************************************************************
 *
 *  test.c
 *
 * A short test of the Athena Widgets and X Toolkit Intrinsics that will be
 * needed for my upcoming game.
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "X11/StringDefs.h"
#include "X11/Intrinsic.h"
#include "X11/Xaw/Form.h"
#include "X11/Xaw/Label.h"
#include "X11/Xaw/Scrollbar.h"

float North = 0;

static void
ThumbedAZ(w,null_ptr,scrl_ptr)
Widget w;
XtPointer null_ptr,scrl_ptr;
{
	float scrl = *((float *) scrl_ptr);

	printf("A = %i\302\260\n",(int) (scrl * 360));
}

static void
ThumbedALT(w,null_ptr,scrl_ptr)
Widget w;
XtPointer null_ptr,scrl_ptr;
{
	float scrl = *((float *) scrl_ptr);

	printf("a = %i\302\260\n",(int) ((scrl * -180) + 90));
}

static void
ThumbedR(w,null_ptr,scrl_ptr)
Widget w;
XtPointer null_ptr,scrl_ptr;
{
	float scrl = *((float *) scrl_ptr);

	printf("r = %im\n",(int) ((scrl * -20) + 10));
}

static void
ThumbedFOV(w,null_ptr,scrl_ptr)
Widget w;
XtPointer null_ptr,scrl_ptr;
{
	float scrl = *((float *) scrl_ptr);

	printf("f = %i\302\260\n",(int) ((scrl * 225) + 45));
}

main(argc,argv)
int argc;
char **argv;
{
	Widget toplevel;
	Widget form0, form1, form2;
	Widget scrollAZ, scrollALT, scrollR, scrollFOV;
	Widget label0, label1, label2, label3, label4, label5, label6, label7;
	Arg wargs[30];
	int n;

	toplevel = XtInitialize(argv[0],"simple",NULL, 0, &argc, argv);

	n = 0;
	XtSetArg(wargs[n],XtNheight,150); n++;
	XtSetArg(wargs[n],XtNwidth,200); n++;
	XtSetValues(toplevel,wargs,n);

	form0 = XtCreateManagedWidget("form0",formWidgetClass,toplevel, NULL, 0);

	scrollAZ = XtCreateManagedWidget("Azimuth",scrollbarWidgetClass,form0, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNright,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNbottom,XawChainBottom); n++;
	XtSetArg(wargs[n],XtNheight,100); n++;
	XtSetValues(scrollAZ,wargs,n);

	scrollALT = XtCreateManagedWidget("Elevation",scrollbarWidgetClass,form0, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNright,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNbottom,XawChainBottom); n++;
	XtSetArg(wargs[n],XtNfromHoriz,scrollAZ); n++;
	XtSetArg(wargs[n],XtNheight,100); n++;
	XtSetValues(scrollALT,wargs,n);

	form1 = XtCreateManagedWidget("form1",formWidgetClass,form0, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNright,XawChainRight); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNfromHoriz,scrollALT); n++;
	XtSetValues(form1,wargs,n);

	form2 = XtCreateManagedWidget("form2",formWidgetClass,form0, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNright,XawChainRight); n++;
	XtSetArg(wargs[n],XtNbottom,XawChainBottom); n++;
	XtSetArg(wargs[n],XtNfromHoriz,scrollALT); n++;
	XtSetArg(wargs[n],XtNfromVert,form1); n++;
	XtSetValues(form2,wargs,n);

	scrollR = XtCreateManagedWidget("Range",scrollbarWidgetClass,form0, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainRight); n++;
	XtSetArg(wargs[n],XtNright,XawChainRight); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNbottom,XawChainBottom); n++;
	XtSetArg(wargs[n],XtNfromHoriz,form1); n++;
	XtSetArg(wargs[n],XtNheight,100); n++;
	XtSetValues(scrollR,wargs,n);

	scrollFOV = XtCreateManagedWidget("Zoom",scrollbarWidgetClass,form0, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainRight); n++;
	XtSetArg(wargs[n],XtNright,XawChainRight); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNbottom,XawChainBottom); n++;
	XtSetArg(wargs[n],XtNfromHoriz,scrollR); n++;
	XtSetArg(wargs[n],XtNheight,100); n++;
	XtSetValues(scrollFOV,wargs,n);

	label0 = XtCreateManagedWidget("Label0",labelWidgetClass,form1, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNlabel,"Label0"); n++;
	XtSetValues(label0,wargs,n);

	label1 = XtCreateManagedWidget("Label1",labelWidgetClass,form1, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNright,XawChainRight); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNfromHoriz,label0); n++;
	XtSetArg(wargs[n],XtNlabel,"Label1"); n++;
	XtSetValues(label1,wargs,n);

	label2 = XtCreateManagedWidget("Label2",labelWidgetClass,form1, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNfromVert,label0); n++;
	XtSetArg(wargs[n],XtNlabel,"Label2"); n++;
	XtSetValues(label2,wargs,n);

	label3 = XtCreateManagedWidget("Label3",labelWidgetClass,form1, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNright,XawChainRight); n++;
	XtSetArg(wargs[n],XtNfromVert,label1); n++;
	XtSetArg(wargs[n],XtNfromHoriz,label2); n++;
	XtSetArg(wargs[n],XtNlabel,"Label3"); n++;
	XtSetValues(label3,wargs,n);

	label4 = XtCreateManagedWidget("Label4",labelWidgetClass,form2, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNlabel,"Label4"); n++;
	XtSetValues(label4,wargs,n);

	label5 = XtCreateManagedWidget("Label5",labelWidgetClass,form2, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNright,XawChainRight); n++;
	XtSetArg(wargs[n],XtNtop,XawChainTop); n++;
	XtSetArg(wargs[n],XtNfromHoriz,label0); n++;
	XtSetArg(wargs[n],XtNlabel,"Label5"); n++;
	XtSetValues(label5,wargs,n);

	label6 = XtCreateManagedWidget("Label6",labelWidgetClass,form2, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNleft,XawChainLeft); n++;
	XtSetArg(wargs[n],XtNlabel,"Label6"); n++;
	XtSetArg(wargs[n],XtNfromVert,label0); n++;
	XtSetValues(label6,wargs,n);

	label7 = XtCreateManagedWidget("Label7",labelWidgetClass,form2, NULL, 0);

	n = 0;
	XtSetArg(wargs[n],XtNright,XawChainRight); n++;
	XtSetArg(wargs[n],XtNfromVert,label1); n++;
	XtSetArg(wargs[n],XtNfromHoriz,label2); n++;
	XtSetArg(wargs[n],XtNlabel,"Label7"); n++;
	XtSetValues(label7,wargs,n);

	XtAddCallback(scrollAZ,XtNjumpProc,ThumbedAZ,NULL);
	XtAddCallback(scrollALT,XtNjumpProc,ThumbedALT,NULL);
	XtAddCallback(scrollR,XtNjumpProc,ThumbedR,NULL);
	XtAddCallback(scrollFOV,XtNjumpProc,ThumbedFOV,NULL);

	XtRealizeWidget(toplevel);

	XtMainLoop();
}
