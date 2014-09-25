#pragma once
#include "MSForm.h"
#include "dip_proc.h"
#include "MySelector.h"
#include "About.h"
namespace MDIP_DIP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Collections::Generic;   

	/// <summary>
	/// Form1 ªººK­n
	///
	/// Äµ§i: ¦pªG±zÅÜ§ó³o­ÓÃþ§Oªº¦WºÙ¡A´N¥²¶·ÅÜ§ó»P³o­ÓÃþ§O©Ò¨Ì¾Ú¤§©Ò¦³ .resx ÀÉ®×ÃöÁpªº
	///          Managed ¸ê·½½sÄ¶¾¹¤u¨ãªº 'Resource File Name' ÄÝ©Ê¡C
	///          §_«h¡A³o¨Ç³]­p¤u¨ã
	///          ±NµLªk»P³o­Óªí³æÃöÁpªº·í¦a»y¨t¤Æ¸ê·½
	///          ¥¿½T¤¬°Ê¡C
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ¦b¦¹¥[¤J«Øºc¨ç¦¡µ{¦¡½X
			//
		}

	protected:
		/// <summary>
		/// ²M°£¥ô¦ó¨Ï¥Î¤¤ªº¸ê·½¡C
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  oFileDlg;
	private: System::Windows::Forms::SaveFileDialog^  sFileDlg;
	internal: System::Windows::Forms::StatusStrip^  stStrip;
	private: 
	internal: System::Windows::Forms::ToolStripStatusLabel^  stStripLabel;
	private: System::Windows::Forms::ToolStripMenuItem^  imageToolStripMenuItem;
	internal: 
	private: System::Windows::Forms::ToolStripMenuItem^  rGBtoGrayToolStripMenuItem;
	internal: Bitmap^ NpBitmap;
	internal: int w, h;


	private: System::Windows::Forms::ToolStripMenuItem^  filtersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bitplaneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bitDepthToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  noiseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  medianToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sharpenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sharpenToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  blurToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blurAverageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  edgeDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  othersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  customToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gaussBlureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gaussDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  laplaceDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  prewittDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  prewittHorzontalDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  prewittVerticalDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobelDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobelHorizontalDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobelVerticalDetectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  transformToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  scaleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  linearScaleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  interpolationScaleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saltAndPepperToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  closeAllWindowsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  adjustToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  invertToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  equalizationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  layerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  maskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redMaskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  greebMaskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blueMaskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  extractToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  redChannelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  greenChannelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blueChannelToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  otsuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  objectDetectionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  luminanceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rotateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dilationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  erosionToolStripMenuItem;

	internal: 
		/*private: 
		List<MSForm> childlist = new List<MSForm>();*/

	private:
		/// <summary>
		/// ³]­p¤u¨ã©Ò»ÝªºÅÜ¼Æ¡C
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ¦¹¬°³]­p¤u¨ã¤ä´©©Ò»Ýªº¤èªk - ½Ð¤Å¨Ï¥Îµ{¦¡½X½s¿è¾¹­×§ï³o­Ó¤èªkªº¤º®e¡C
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeAllWindowsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bitplaneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bitDepthToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->transformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->scaleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->interpolationScaleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->linearScaleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->objectDetectionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adjustToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->invertToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->equalizationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rGBtoGrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->otsuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->luminanceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rotateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->layerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->maskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redMaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->greebMaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blueMaskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->extractToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redChannelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->greenChannelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blueChannelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filtersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blurToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blurAverageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gaussBlureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sharpenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sharpenToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->edgeDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prewittDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prewittHorzontalDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->prewittVerticalDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobelDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobelHorizontalDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobelVerticalDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gaussDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->laplaceDetectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->noiseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->medianToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saltAndPepperToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->othersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->customToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dilationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->erosionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oFileDlg = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sFileDlg = (gcnew System::Windows::Forms::SaveFileDialog());
			this->stStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->stStripLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1->SuspendLayout();
			this->stStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->fileToolStripMenuItem, 
				this->editToolStripMenuItem, this->toolsToolStripMenuItem, this->imageToolStripMenuItem, this->layerToolStripMenuItem, this->filtersToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(624, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->openToolStripMenuItem, 
				this->saveAsToolStripMenuItem, this->closeAllWindowsToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->openToolStripMenuItem->Text = L"&Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->saveAsToolStripMenuItem->Text = L"Save as ...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsToolStripMenuItem_Click);
			// 
			// closeAllWindowsToolStripMenuItem
			// 
			this->closeAllWindowsToolStripMenuItem->Name = L"closeAllWindowsToolStripMenuItem";
			this->closeAllWindowsToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->closeAllWindowsToolStripMenuItem->Text = L"Close All Windows";
			this->closeAllWindowsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::closeAllWindowsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->bitplaneToolStripMenuItem, 
				this->bitDepthToolStripMenuItem1, this->transformToolStripMenuItem});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// bitplaneToolStripMenuItem
			// 
			this->bitplaneToolStripMenuItem->Name = L"bitplaneToolStripMenuItem";
			this->bitplaneToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->bitplaneToolStripMenuItem->Text = L"Bitplane";
			this->bitplaneToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::bitplaneToolStripMenuItem_Click);
			// 
			// bitDepthToolStripMenuItem1
			// 
			this->bitDepthToolStripMenuItem1->Name = L"bitDepthToolStripMenuItem1";
			this->bitDepthToolStripMenuItem1->Size = System::Drawing::Size(129, 22);
			this->bitDepthToolStripMenuItem1->Text = L"Bit Depth";
			this->bitDepthToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::bitDepthToolStripMenuItem1_Click);
			// 
			// transformToolStripMenuItem
			// 
			this->transformToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->scaleToolStripMenuItem});
			this->transformToolStripMenuItem->Name = L"transformToolStripMenuItem";
			this->transformToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->transformToolStripMenuItem->Text = L"Transform";
			// 
			// scaleToolStripMenuItem
			// 
			this->scaleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->interpolationScaleToolStripMenuItem, 
				this->linearScaleToolStripMenuItem});
			this->scaleToolStripMenuItem->Name = L"scaleToolStripMenuItem";
			this->scaleToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->scaleToolStripMenuItem->Text = L"Scale";
			// 
			// interpolationScaleToolStripMenuItem
			// 
			this->interpolationScaleToolStripMenuItem->Name = L"interpolationScaleToolStripMenuItem";
			this->interpolationScaleToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->interpolationScaleToolStripMenuItem->Text = L"Nearest Scale";
			this->interpolationScaleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::interpolationScaleToolStripMenuItem_Click);
			// 
			// linearScaleToolStripMenuItem
			// 
			this->linearScaleToolStripMenuItem->Name = L"linearScaleToolStripMenuItem";
			this->linearScaleToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->linearScaleToolStripMenuItem->Text = L"Linear Scale";
			this->linearScaleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::linearScaleToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->objectDetectionToolStripMenuItem});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// objectDetectionToolStripMenuItem
			// 
			this->objectDetectionToolStripMenuItem->Name = L"objectDetectionToolStripMenuItem";
			this->objectDetectionToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->objectDetectionToolStripMenuItem->Text = L"Object Detection";
			this->objectDetectionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::objectDetectionToolStripMenuItem_Click);
			// 
			// imageToolStripMenuItem
			// 
			this->imageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->adjustToolStripMenuItem, 
				this->rGBtoGrayToolStripMenuItem, this->histogramToolStripMenuItem, this->otsuToolStripMenuItem, this->luminanceToolStripMenuItem, 
				this->rotateToolStripMenuItem});
			this->imageToolStripMenuItem->Name = L"imageToolStripMenuItem";
			this->imageToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->imageToolStripMenuItem->Text = L"Image";
			// 
			// adjustToolStripMenuItem
			// 
			this->adjustToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->invertToolStripMenuItem, 
				this->equalizationToolStripMenuItem});
			this->adjustToolStripMenuItem->Name = L"adjustToolStripMenuItem";
			this->adjustToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->adjustToolStripMenuItem->Text = L"Adjust";
			// 
			// invertToolStripMenuItem
			// 
			this->invertToolStripMenuItem->Name = L"invertToolStripMenuItem";
			this->invertToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->invertToolStripMenuItem->Text = L"Invert";
			this->invertToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::invertToolStripMenuItem_Click);
			// 
			// equalizationToolStripMenuItem
			// 
			this->equalizationToolStripMenuItem->Name = L"equalizationToolStripMenuItem";
			this->equalizationToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->equalizationToolStripMenuItem->Text = L"Equalization";
			this->equalizationToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::equalizationToolStripMenuItem_Click);
			// 
			// rGBtoGrayToolStripMenuItem
			// 
			this->rGBtoGrayToolStripMenuItem->Name = L"rGBtoGrayToolStripMenuItem";
			this->rGBtoGrayToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->rGBtoGrayToolStripMenuItem->Text = L"RGBtoGray";
			this->rGBtoGrayToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rGBtoGrayToolStripMenuItem_Click);
			// 
			// histogramToolStripMenuItem
			// 
			this->histogramToolStripMenuItem->Name = L"histogramToolStripMenuItem";
			this->histogramToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->histogramToolStripMenuItem->Text = L"Histogram";
			this->histogramToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::histogramToolStripMenuItem_Click);
			// 
			// otsuToolStripMenuItem
			// 
			this->otsuToolStripMenuItem->Name = L"otsuToolStripMenuItem";
			this->otsuToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->otsuToolStripMenuItem->Text = L"Otsu";
			this->otsuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::otsuToolStripMenuItem_Click);
			// 
			// luminanceToolStripMenuItem
			// 
			this->luminanceToolStripMenuItem->Name = L"luminanceToolStripMenuItem";
			this->luminanceToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->luminanceToolStripMenuItem->Text = L"Luminance";
			this->luminanceToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::luminanceToolStripMenuItem_Click);
			// 
			// rotateToolStripMenuItem
			// 
			this->rotateToolStripMenuItem->Name = L"rotateToolStripMenuItem";
			this->rotateToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->rotateToolStripMenuItem->Text = L"Rotate";
			this->rotateToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rotateToolStripMenuItem_Click);
			// 
			// layerToolStripMenuItem
			// 
			this->layerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->maskToolStripMenuItem, 
				this->extractToolStripMenuItem});
			this->layerToolStripMenuItem->Name = L"layerToolStripMenuItem";
			this->layerToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->layerToolStripMenuItem->Text = L"Layer";
			// 
			// maskToolStripMenuItem
			// 
			this->maskToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->redMaskToolStripMenuItem, 
				this->greebMaskToolStripMenuItem, this->blueMaskToolStripMenuItem});
			this->maskToolStripMenuItem->Name = L"maskToolStripMenuItem";
			this->maskToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->maskToolStripMenuItem->Text = L"Mask";
			// 
			// redMaskToolStripMenuItem
			// 
			this->redMaskToolStripMenuItem->Name = L"redMaskToolStripMenuItem";
			this->redMaskToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->redMaskToolStripMenuItem->Text = L"Red Mask";
			this->redMaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::redMaskToolStripMenuItem_Click);
			// 
			// greebMaskToolStripMenuItem
			// 
			this->greebMaskToolStripMenuItem->Name = L"greebMaskToolStripMenuItem";
			this->greebMaskToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->greebMaskToolStripMenuItem->Text = L"Green Mask";
			this->greebMaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::greebMaskToolStripMenuItem_Click);
			// 
			// blueMaskToolStripMenuItem
			// 
			this->blueMaskToolStripMenuItem->Name = L"blueMaskToolStripMenuItem";
			this->blueMaskToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->blueMaskToolStripMenuItem->Text = L"Blue Mask";
			this->blueMaskToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::blueMaskToolStripMenuItem_Click);
			// 
			// extractToolStripMenuItem
			// 
			this->extractToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->redChannelToolStripMenuItem, 
				this->greenChannelToolStripMenuItem, this->blueChannelToolStripMenuItem});
			this->extractToolStripMenuItem->Name = L"extractToolStripMenuItem";
			this->extractToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->extractToolStripMenuItem->Text = L"Extract";
			// 
			// redChannelToolStripMenuItem
			// 
			this->redChannelToolStripMenuItem->Name = L"redChannelToolStripMenuItem";
			this->redChannelToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->redChannelToolStripMenuItem->Text = L"Red Channel";
			this->redChannelToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::redChannelToolStripMenuItem_Click);
			// 
			// greenChannelToolStripMenuItem
			// 
			this->greenChannelToolStripMenuItem->Name = L"greenChannelToolStripMenuItem";
			this->greenChannelToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->greenChannelToolStripMenuItem->Text = L"Green Channel";
			this->greenChannelToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::greenChannelToolStripMenuItem_Click);
			// 
			// blueChannelToolStripMenuItem
			// 
			this->blueChannelToolStripMenuItem->Name = L"blueChannelToolStripMenuItem";
			this->blueChannelToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->blueChannelToolStripMenuItem->Text = L"Blue Channel";
			this->blueChannelToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::blueChannelToolStripMenuItem_Click);
			// 
			// filtersToolStripMenuItem
			// 
			this->filtersToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->blurToolStripMenuItem, 
				this->sharpenToolStripMenuItem, this->edgeDetectToolStripMenuItem, this->noiseToolStripMenuItem, this->othersToolStripMenuItem, 
				this->dilationToolStripMenuItem, this->erosionToolStripMenuItem});
			this->filtersToolStripMenuItem->Name = L"filtersToolStripMenuItem";
			this->filtersToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->filtersToolStripMenuItem->Text = L"Filters";
			// 
			// blurToolStripMenuItem
			// 
			this->blurToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->blurAverageToolStripMenuItem, 
				this->gaussBlureToolStripMenuItem});
			this->blurToolStripMenuItem->Name = L"blurToolStripMenuItem";
			this->blurToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->blurToolStripMenuItem->Text = L"Blur";
			// 
			// blurAverageToolStripMenuItem
			// 
			this->blurAverageToolStripMenuItem->Name = L"blurAverageToolStripMenuItem";
			this->blurAverageToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->blurAverageToolStripMenuItem->Text = L"Average Blure";
			this->blurAverageToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::averageBlureToolStripMenuItem_Click);
			// 
			// gaussBlureToolStripMenuItem
			// 
			this->gaussBlureToolStripMenuItem->Name = L"gaussBlureToolStripMenuItem";
			this->gaussBlureToolStripMenuItem->Size = System::Drawing::Size(147, 22);
			this->gaussBlureToolStripMenuItem->Text = L"Gauss Blure";
			this->gaussBlureToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::gaussBlureToolStripMenuItem_Click);
			// 
			// sharpenToolStripMenuItem
			// 
			this->sharpenToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->sharpenToolStripMenuItem1});
			this->sharpenToolStripMenuItem->Name = L"sharpenToolStripMenuItem";
			this->sharpenToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->sharpenToolStripMenuItem->Text = L"Sharpen";
			// 
			// sharpenToolStripMenuItem1
			// 
			this->sharpenToolStripMenuItem1->Name = L"sharpenToolStripMenuItem1";
			this->sharpenToolStripMenuItem1->Size = System::Drawing::Size(117, 22);
			this->sharpenToolStripMenuItem1->Text = L"Sharpen";
			this->sharpenToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::sharpenToolStripMenuItem_Click);
			// 
			// edgeDetectToolStripMenuItem
			// 
			this->edgeDetectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->prewittDetectToolStripMenuItem, 
				this->sobelDetectToolStripMenuItem, this->gaussDetectToolStripMenuItem, this->laplaceDetectToolStripMenuItem});
			this->edgeDetectToolStripMenuItem->Name = L"edgeDetectToolStripMenuItem";
			this->edgeDetectToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->edgeDetectToolStripMenuItem->Text = L"Edge Detect";
			// 
			// prewittDetectToolStripMenuItem
			// 
			this->prewittDetectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->prewittHorzontalDetectToolStripMenuItem, 
				this->prewittVerticalDetectToolStripMenuItem});
			this->prewittDetectToolStripMenuItem->Name = L"prewittDetectToolStripMenuItem";
			this->prewittDetectToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->prewittDetectToolStripMenuItem->Text = L"Prewitt Detect";
			// 
			// prewittHorzontalDetectToolStripMenuItem
			// 
			this->prewittHorzontalDetectToolStripMenuItem->Name = L"prewittHorzontalDetectToolStripMenuItem";
			this->prewittHorzontalDetectToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->prewittHorzontalDetectToolStripMenuItem->Text = L"Prewitt Horzontal Detect";
			this->prewittHorzontalDetectToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::prewittHorzontalDetectToolStripMenuItem_Click);
			// 
			// prewittVerticalDetectToolStripMenuItem
			// 
			this->prewittVerticalDetectToolStripMenuItem->Name = L"prewittVerticalDetectToolStripMenuItem";
			this->prewittVerticalDetectToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->prewittVerticalDetectToolStripMenuItem->Text = L"Prewitt Vertical Detect";
			this->prewittVerticalDetectToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::prewittVerticalDetectToolStripMenuItem_Click);
			// 
			// sobelDetectToolStripMenuItem
			// 
			this->sobelDetectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->sobelHorizontalDetectToolStripMenuItem, 
				this->sobelVerticalDetectToolStripMenuItem});
			this->sobelDetectToolStripMenuItem->Name = L"sobelDetectToolStripMenuItem";
			this->sobelDetectToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->sobelDetectToolStripMenuItem->Text = L"Sobel Detect";
			// 
			// sobelHorizontalDetectToolStripMenuItem
			// 
			this->sobelHorizontalDetectToolStripMenuItem->Name = L"sobelHorizontalDetectToolStripMenuItem";
			this->sobelHorizontalDetectToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->sobelHorizontalDetectToolStripMenuItem->Text = L"Sobel Horizontal Detect";
			this->sobelHorizontalDetectToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sobelHorizontalDetectToolStripMenuItem_Click);
			// 
			// sobelVerticalDetectToolStripMenuItem
			// 
			this->sobelVerticalDetectToolStripMenuItem->Name = L"sobelVerticalDetectToolStripMenuItem";
			this->sobelVerticalDetectToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->sobelVerticalDetectToolStripMenuItem->Text = L"Sobel Vertical Detect";
			this->sobelVerticalDetectToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sobelVerticalDetectToolStripMenuItem_Click);
			// 
			// gaussDetectToolStripMenuItem
			// 
			this->gaussDetectToolStripMenuItem->Name = L"gaussDetectToolStripMenuItem";
			this->gaussDetectToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->gaussDetectToolStripMenuItem->Text = L"Gauss Detect";
			this->gaussDetectToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::gaussDetectToolStripMenuItem_Click);
			// 
			// laplaceDetectToolStripMenuItem
			// 
			this->laplaceDetectToolStripMenuItem->Name = L"laplaceDetectToolStripMenuItem";
			this->laplaceDetectToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->laplaceDetectToolStripMenuItem->Text = L"Laplace Detect";
			this->laplaceDetectToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::laplaceDetectToolStripMenuItem_Click);
			// 
			// noiseToolStripMenuItem
			// 
			this->noiseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->medianToolStripMenuItem, 
				this->saltAndPepperToolStripMenuItem});
			this->noiseToolStripMenuItem->Name = L"noiseToolStripMenuItem";
			this->noiseToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->noiseToolStripMenuItem->Text = L"Noise";
			// 
			// medianToolStripMenuItem
			// 
			this->medianToolStripMenuItem->Name = L"medianToolStripMenuItem";
			this->medianToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->medianToolStripMenuItem->Text = L"Median";
			this->medianToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::medianToolStripMenuItem_Click);
			// 
			// saltAndPepperToolStripMenuItem
			// 
			this->saltAndPepperToolStripMenuItem->Name = L"saltAndPepperToolStripMenuItem";
			this->saltAndPepperToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->saltAndPepperToolStripMenuItem->Text = L"Salt and Pepper";
			this->saltAndPepperToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saltAndPepperToolStripMenuItem_Click);
			// 
			// othersToolStripMenuItem
			// 
			this->othersToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->customToolStripMenuItem});
			this->othersToolStripMenuItem->Name = L"othersToolStripMenuItem";
			this->othersToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->othersToolStripMenuItem->Text = L"Others";
			// 
			// customToolStripMenuItem
			// 
			this->customToolStripMenuItem->Name = L"customToolStripMenuItem";
			this->customToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->customToolStripMenuItem->Text = L"Custom";
			this->customToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::customToolStripMenuItem_Click);
			// 
			// dilationToolStripMenuItem
			// 
			this->dilationToolStripMenuItem->Name = L"dilationToolStripMenuItem";
			this->dilationToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->dilationToolStripMenuItem->Text = L"Dilation";
			this->dilationToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::dilationToolStripMenuItem_Click);
			// 
			// erosionToolStripMenuItem
			// 
			this->erosionToolStripMenuItem->Name = L"erosionToolStripMenuItem";
			this->erosionToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->erosionToolStripMenuItem->Text = L"Erosion";
			this->erosionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::erosionToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// oFileDlg
			// 
			this->oFileDlg->FileName = L"openFileDialog1";
			// 
			// stStrip
			// 
			this->stStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->stStripLabel});
			this->stStrip->Location = System::Drawing::Point(0, 419);
			this->stStrip->Name = L"stStrip";
			this->stStrip->Size = System::Drawing::Size(624, 22);
			this->stStrip->TabIndex = 2;
			this->stStrip->Text = L"statusStrip1";
			this->stStrip->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Form1::stStrip_ItemClicked);
			// 
			// stStripLabel
			// 
			this->stStripLabel->Name = L"stStripLabel";
			this->stStripLabel->Size = System::Drawing::Size(68, 17);
			this->stStripLabel->Text = L"stStripLabel";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->stStrip);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"DIPSample";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->stStrip->ResumeLayout(false);
			this->stStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->IsMdiContainer = true;
				 this->WindowState = FormWindowState::Maximized;
				 this->stStripLabel->Text = ""; 
			 }
	private: Bitmap^ imgRead2Bmp(OpenFileDialog^ oFileDlg)
			 {
				 String^ fileloc = oFileDlg->FileName;
				 Bitmap^ pBitmap0 = gcnew Bitmap(fileloc);
				 this->Text = oFileDlg->SafeFileName;
				 return pBitmap0;
			 }
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Declare the child form as a new one.  
				 //OpenFileDialog^ oFD;
				 //Bitmap^ pBitmap;
				 oFileDlg->CheckFileExists = true;
				 oFileDlg->CheckPathExists = true;
				 oFileDlg->Title = "Open File - DIP Sample";
				 oFileDlg->ValidateNames = true;
				 oFileDlg->Filter = "Image|*.bmp;*.jpg;*.png;*.tif;*.gif|Bitmap Image|*.bmp|JPeg Image|*.jpg|Png Image|*.png|Tiff Image|*.tif|GIF Image|*.gif";//|EXIF Image|*.exif|ICON Image|*.ico";;*.exif;*.ico
				 oFileDlg->FileName = "";
				 if (oFileDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 MSForm^ childForm = gcnew MSForm();
					 childForm->MdiParent = this;
					 childForm->pf1 = stStripLabel;
					 NpBitmap = imgRead2Bmp(oFileDlg);
					 childForm->pBitmap = NpBitmap;  
					 w = NpBitmap->Width;
					 h = NpBitmap->Height;
					 childForm->Show();
				 }
			 }
	private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 //sFileDlg->CheckFileExists = true;
				 //sFileDlg->CheckPathExists = true;
				 sFileDlg->Title = "Save File - DIP Sample";
				 sFileDlg->ValidateNames = true;
				 sFileDlg->Filter = "Bitmap Image|*.bmp|JPeg Image|*.jpg|Png Image|*.png|Tiff Image|*.tif|GIF Image|*.gif";//|EXIF Image|*.exif|ICON Image|*.ico";
				 sFileDlg->FileName = "New image";
				 sFileDlg->ShowDialog();
				 if (sFileDlg->FileName != "")
				 {
					 MSForm^ cF = winFocused();
					 // Saves the Image through a FileStream created by
					 // the OpenFile method.
					 System::IO::FileStream ^fs = safe_cast<System::IO::FileStream^>(sFileDlg->OpenFile());
					 // Saves the Image in the appropriate ImageFormat based on
					 // the file type selected in the dialog box.
					 // Note that the FilterIndex property is one based.
					 switch(sFileDlg->FilterIndex)
					 {
					 case 1 :
						 cF->pBitmap->Save(fs, System::Drawing::Imaging::ImageFormat::Bmp);
						 break;
					 case 2 :
						 cF->pBitmap->Save(fs, System::Drawing::Imaging::ImageFormat::Jpeg);
						 break;
					 case 3 :
						 cF->pBitmap->Save(fs, System::Drawing::Imaging::ImageFormat::Png);
						 break;
					 case 4 :
						 cF->pBitmap->Save(fs, System::Drawing::Imaging::ImageFormat::Tiff);
						 break;
					 case 5 :
						 cF->pBitmap->Save(fs, System::Drawing::Imaging::ImageFormat::Gif);
						 break;
					 case 6 :
						 cF->pBitmap->Save(fs, System::Drawing::Imaging::ImageFormat::Exif);
						 break;
					 case 7 :
						 cF->pBitmap->Save(fs, System::Drawing::Imaging::ImageFormat::Icon);
						 break;
					 }
					 fs->Close();
				 }
			 }
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 exit(0);
			 }
	private: System::Void closeAllWindowsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 for each (MSForm^ cF in MdiChildren)
				 {
					 cF->Close();
				 }
			 }
	private: System::Void stStrip_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e)
			 {
			 }
			 /***************************************tools****************************************/
	private: int** bmp2array(Bitmap^ bmp)
			 {
				 int w = bmp->Width, h  = bmp->Height;
				 int **imgData = new int*[3];
				 *(imgData) = new int[w*h];
				 *(imgData + 1) = new int[w*h];
				 *(imgData + 2) = new int[w*h];
				 BitmapData^ bmpData = 
					 bmp->LockBits(Rectangle(0,0,w,h),ImageLockMode::ReadOnly,PixelFormat::Format24bppRgb);
				 //int ByteOfSkip = bmpData->Stride - bmpData->Width * 3;

				 int stride = bmpData->Stride;
				 array<unsigned char> ^rawData = gcnew array<unsigned char>(stride * h);
				 System::Runtime::InteropServices::Marshal::Copy(bmpData->Scan0, rawData, 0, rawData->Length);

				 int size = w * h;

				 for (int i = 0; i < size; i++)
				 {
					 int loc = (bmpData->Stride * (i / w)) + ((i % w) * 3);
					 *(*(imgData + 2) + i) = rawData[loc];
					 *(*(imgData + 1) + i) = rawData[loc + 1];
					 *(*(imgData + 0) + i) = rawData[loc + 2];
				 }

				 bmp->UnlockBits(bmpData);
				 return imgData;
			 }
	private: Bitmap^ array2bmp(int **g, int w, int h)
			 {
				 Bitmap^ bmp  = gcnew Bitmap(w, h, PixelFormat::Format24bppRgb);

				 BitmapData^ bmpData = 
					 bmp->LockBits(Rectangle(0,0,w,h),ImageLockMode::WriteOnly,PixelFormat::Format24bppRgb);

				 int stride = bmpData->Stride;
				 array<Byte> ^rawData = gcnew array<Byte>(stride * h);

				 int size = w * h;

				 for (int i = 0; i < size; i++)
				 {
					 int loc = (bmpData->Stride * (i / w)) + ((i % w) * 3);
					 rawData[loc + 2] = Convert::ToByte(*(*(g) + i));
					 rawData[loc + 1] = Convert::ToByte(*(*(g + 1) + i));
					 rawData[loc + 0] = Convert::ToByte(*(*(g + 2) + i));
				 }

				 System::Runtime::InteropServices::Marshal::Copy(rawData, 0, bmpData->Scan0, rawData->Length);
				 bmp->UnlockBits(bmpData);
				 return bmp;
			 }
	private: inline void createBmpForm(Bitmap^ NpBitmap)
			 {
				 MSForm^ childForm = gcnew MSForm();
				 childForm->MdiParent = this;
				 childForm->pf1 = stStripLabel;
				 childForm->pBitmap = NpBitmap; 
				 childForm->Show();
			 }
	private: inline void createBmpForm(Bitmap^ NpBitmap, System::String ^title)
			 {
				 MSForm^ childForm = gcnew MSForm(title);
				 childForm->MdiParent = this;
				 childForm->pf1 = stStripLabel;
				 childForm->pBitmap = NpBitmap; 
				 childForm->Show();
			 }
	private: inline MSForm^ winFocused()
			 {
				 for each (MSForm^ cF in MdiChildren)
				 {
					 if (cF->Focused)
					 {
						 return cF;
					 }
				 }
			 }
	private: inline int inputeNumDialog(String^ title,String^ explain,int faliure)
			 {
				 MySelector^ selectForm = gcnew MySelector(explain);
				 selectForm->ShowDialog();
				 if(selectForm->getcolord()->Length > 0){
					 int num = 0;
					 for(int i = 0;i < selectForm->getcolord()->Length;i++){
						 if((selectForm->getcolord()[i] <= '9'))
							 num += pow(10,selectForm->getcolord()->Length - i - 1) * (selectForm->getcolord()[i] - '0');
					 }
					 return num;
				 }
				 return faliure;
			 }
			 /****************************************Other*******menue***********************************/
	private: System::Void rGBtoGrayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = Grayscale(bmp2array(cF->pBitmap),w,h);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void invertToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = Invert(bmp2array(cF->pBitmap),w,h);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }

	private: System::Void bitplaneToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 int bit = inputeNumDialog(L"Bitplane", L"Enter a number from 0 to 7!", -1);
				 if(bit != -1){
					 img = BitPlane(bmp2array(cF->pBitmap),w,h,bit);
					 bmp = array2bmp(img,w,h);
					 createBmpForm(bmp);
				 }
			 }
	private: System::Void bitDepthToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 int bit = inputeNumDialog(L"Bitplane", L"Enter a number from 0 to 7!",-1);
				 if(bit != -1){
					 img = BitDepth(bmp2array(cF->pBitmap),w,h,bit);
					 bmp = array2bmp(img,w,h);
					 createBmpForm(bmp);
				 }
			 }
	private: System::Void medianToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = Median(bmp2array(cF->pBitmap),w,h,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void sharpenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float a = inputeNumDialog(L"Sharpen", L"Enter a number from 0 to 9!",-1);
				 if(a != -1){
					 float b = a - 1;
					 float ptr[9] = {0.111,0.111,0.111,0.111,0.111,0.111,0.111,0.111,0.111};
					 for(int i = 0;i < 9;i++) ptr[i] *= b * -1;
					 ptr[4] += a * 1.0;

					 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
					 bmp = array2bmp(img,w,h);
					 createBmpForm(bmp);
				 }
			 }

	private: System::Void averageBlureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float ptr[9] = {0.111,0.111,0.111,0.111,0.111,0.111,0.111,0.111,0.111};

				 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void gaussBlureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float ptr[9] = {0.0113,0.0838,0.0113,0.0838,0.6193,0.0838,0.0113,0.0838,0.0113};

				 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }

	private: System::Void customToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {

			 }
	private: System::Void gaussDetectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float ptr[9] = {1,1,1,1,-8,1,1,1,1};

				 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void laplaceDetectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float ptr[9] = {0,1,0,1,-4,1,0,1,0};

				 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void prewittHorzontalDetectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float ptr[9] = {1,1,1,0,0,0,-1,-1,-1};

				 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void prewittVerticalDetectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float ptr[9] = {1,0,-1,1,0,-1,1,0,-1};

				 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void sobelHorizontalDetectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float ptr[9] = {1,2,1,0,0,0,-1,-2,-1};

				 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void sobelVerticalDetectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 float ptr[9] = {1,0,-1,2,0,-2,1,0,-1};

				 img = Filter(bmp2array(cF->pBitmap),w,h,ptr,3);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void equalizationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = histogramEqualization(bmp2array(cF->pBitmap),w,h);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void interpolationScaleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 float a = inputeNumDialog(L"Scale", L"Enter a number(percentage%)",-1);
				 if(a != -1)
				 {
					 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
					 int** img;
					 a /= 100;

					 img = interpolationScale(bmp2array(cF->pBitmap),w,h,a,a);
					 w *= a;
					 h *= a;
					 bmp = array2bmp(img,w,h);
					 createBmpForm(bmp);
				 }
			 }
	private: System::Void linearScaleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 float a = inputeNumDialog(L"Linear Scale", L"Enter a number(percentage%)",-1);

				 if(a != -1)
				 {
					 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
					 int** img;
					 a /= 100;

					 img = linaerScale(bmp2array(cF->pBitmap),w,h,a,a);
					 w *= a;
					 h *= a;
					 bmp = array2bmp(img,w,h);
					 createBmpForm(bmp);
				 }
			 }
	private: System::Void saltAndPepperToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 float a = inputeNumDialog(L"Salt and Pepper", L"Enter a number from 0 to 100(percentage%)",-1);

				 if(a != -1)
				 {
					 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
					 int** img;
					 a /= 100;
					 img = noiseSaltAndPepper(bmp2array(cF->pBitmap),w,h,a);
					 bmp = array2bmp(img,w,h);
					 createBmpForm(bmp);
				 }
			 }

			 /*	private: System::Void testToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
			 MSForm^ cF = winFocused();
			 Bitmap^ bmp;

			 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
			 int** img;

			 img = luminanceTemperature(bmp2array(cF->pBitmap),w,h);
			 bmp = array2bmp(img,w,h);
			 createBmpForm(bmp);
			 }
			 */
	private: System::Void histogramToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = histogram(bmp2array(cF->pBitmap),w,h);
				 //TODO wait for delete
				 img = interpolationScale(img,256,256,2,1);
				 bmp = array2bmp(img,512,256);
				 createBmpForm(bmp);
			 }
	private: System::Void redMaskToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = colorMask(bmp2array(cF->pBitmap),w,h,255, 0, 0);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void greebMaskToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = colorMask(bmp2array(cF->pBitmap),w,h, 0, 255, 0);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void blueMaskToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = colorMask(bmp2array(cF->pBitmap),w,h, 0, 0, 255);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void redChannelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = colorMask(bmp2array(cF->pBitmap),w,h, 0, 255, 255);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void greenChannelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = colorMask(bmp2array(cF->pBitmap),w,h, 255, 0, 255);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void blueChannelToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = colorMask(bmp2array(cF->pBitmap),w,h, 255, 255, 0);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
			 /*	private: System::Void duplicateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
			 MSForm^ cF = winFocused();
			 Bitmap^ bmp;

			 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
			 int** img;

			 img = duplicate(bmp2array(cF->pBitmap),w,h);
			 bmp = array2bmp(img,w,h);
			 createBmpForm(bmp);
			 }*/
	private: System::Void otsuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 double threshold[3];

				 img = otsu(bmp2array(cF->pBitmap),w,h,threshold);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp,"Picture with threshold = " + threshold[0].ToString());
			 }
	private: System::Void objectDetectionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;
				 int number(0);
				 img = ObjectsDetection(bmp2array(cF->pBitmap),w,h,number);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp,"Dectected Objects = " + number.ToString());
			 }
	private: System::Void luminanceToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = luminanceTemperature(bmp2array(cF->pBitmap),w,h);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 About^ childForm = gcnew About();
				 childForm->ShowDialog();
			 }
	private: System::Void rotateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;
				 float a = inputeNumDialog(L"Salt and Pepper", L"Enter a number from 0 to 360",-1);

				 if(a != -1)
				 {
					 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
					 int** img;
					 int wh[2];

					 img = rotate(bmp2array(cF->pBitmap),w,h,wh,a);
					 bmp = array2bmp(img,wh[0],wh[1]);
					 createBmpForm(bmp);
				 }
			 }
	private: System::Void dilationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = dilation(bmp2array(cF->pBitmap),w,h);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	private: System::Void erosionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 MSForm^ cF = winFocused();
				 Bitmap^ bmp;

				 int w = cF->pBitmap->Width,h = cF->pBitmap->Height;
				 int** img;

				 img = erosion(bmp2array(cF->pBitmap),w,h);
				 bmp = array2bmp(img,w,h);
				 createBmpForm(bmp);
			 }
	};
}

