/** @file

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __HDA_VERB_TABLE_H__
#define __HDA_VERB_TABLE_H__

#include <Library/BaseLib.h>

#define NHLT_ACPI_TABLE_SIGNATURE  SIGNATURE_32 ('N', 'H', 'L', 'T')

///
/// Use this macro to create HDAUDIO_VERB_TABLE and populate size automatically
///
#define HDAUDIO_VERB_TABLE_INIT(Vid,Did,Rid,Sdi,...) \
{ \
  { Vid, Did, Rid, Sdi, (sizeof((UINT32[]){__VA_ARGS__})/sizeof(UINT32)) }, \
  { __VA_ARGS__ } \
}

/**
  Azalia verb table header
  Every verb table should contain this defined header and followed by azalia verb commands.
**/
typedef struct {
  UINT16  VendorId;             ///< Codec Vendor ID
  UINT16  DeviceId;             ///< Codec Device ID
  UINT8   RevisionId;           ///< Revision ID of the codec. 0xFF matches any revision.
  UINT8   SdiNum;               ///< SDI number, 0xFF matches any SDI.
  UINT16  DataDwords;           ///< Number of data DWORDs following the header.
} PCH_HDA_VERB_TABLE_HEADER;

#ifdef _MSC_VER
//
// Disable "zero-sized array in struct/union" extension warning.
// Used for neater verb table definitions.
//
#pragma warning (push)
#pragma warning (disable: 4200)
#endif
typedef struct  {
  PCH_HDA_VERB_TABLE_HEADER  Header;
  UINT32 Data[];
} HDAUDIO_VERB_TABLE;
#ifdef _MSC_VER
#pragma warning (pop)
#endif

CONST HDAUDIO_VERB_TABLE HdaVerbTableDisplayAudio = HDAUDIO_VERB_TABLE_INIT (
  //
  //  VerbTable: CFL Display Audio Codec
  //  Revision ID = 0xFF
  //  Codec Vendor: 0x8086280B
  //
  0x8086, 0x280B,
  0xFF, 0xFF,
  //
  // Display Audio Verb Table
  //
  // For GEN9, the Vendor Node ID is 08h
  // Port to be exposed to the inbox driver in the vanilla mode: PORT C - BIT[7:6] = 01b
  0x00878140,
  // Pin Widget 5 - PORT B - Configuration Default: 0x18560010
  0x00571C10,
  0x00571D00,
  0x00571E56,
  0x00571F18,
  // Pin Widget 6 - PORT C - Configuration Default: 0x18560020
  0x00671C20,
  0x00671D00,
  0x00671E56,
  0x00671F18,
  // Pin Widget 7 - PORT D - Configuration Default: 0x18560030
  0x00771C30,
  0x00771D00,
  0x00771E56,
  0x00771F18,
  // Disable the third converter and third Pin (NID 08h)
  0x00878140
);

//
// CFL S Audio Codec
// what we had in CNL for Alc700 won't work here , due to board changes
// Audio codec would not be detected in device manager with CNL's Verb Table
//
CONST HDAUDIO_VERB_TABLE CflSHdaVerbTableAlc700 = HDAUDIO_VERB_TABLE_INIT (
  //
  //  VerbTable: (Realtek ALC700) CFL S RVP
  //  Revision ID = 0xff
  //  Codec Verb Table for CNL PCH boards
  //  Codec Address: CAd value (0/1/2)
  //  Codec Vendor: 0x10EC0700
  //
  0x10EC, 0x0700,
  0xFF, 0xFF,

  //===================================================================================================
  //
  //                               Realtek Semiconductor Corp.
  //
  //===================================================================================================

  //Realtek High Definition Audio Configuration - Version : 5.0.3.1
  //Realtek HD Audio Codec : ALC700
  //PCI PnP ID : PCI\VEN_8086&DEV_2668&SUBSYS_72708086
  //HDA Codec PnP ID : HDAUDIO\FUNC_01&VEN_10EC&DEV_0700&SUBSYS_10EC112C
  //The number of verb command block : 17

  //    NID 0x12 : 0x90A60130
  //    NID 0x13 : 0x40000000
  //    NID 0x14 : 0x411111F0
  //    NID 0x15 : 0x411111F0
  //    NID 0x16 : 0x03011010
  //    NID 0x17 : 0x90170120
  //    NID 0x18 : 0x411111F0
  //    NID 0x19 : 0x04A1103E
  //    NID 0x1A : 0x411111F0
  //    NID 0x1B : 0x03A11040
  //    NID 0x1D : 0x40600001
  //    NID 0x1E : 0x411111F0
  //    NID 0x1F : 0x411111F0
  //    NID 0x21 : 0x0421102F
  //    NID 0x29 : 0x411111F0


  //===== HDA Codec Subsystem ID Verb-table =====
  //HDA Codec Subsystem ID  : 0x10EC112C
  0x0017202C,
  0x00172111,
  0x001722EC,
  0x00172310,


  //===== Pin Widget Verb-table =====
  //Widget node 0x01 :
  0x0017FF00,
  0x0017FF00,
  0x0017FF00,
  0x0017FF00,
  //Pin widget 0x12 - DMIC
  0x01271C30,
  0x01271D01,
  0x01271EA6,
  0x01271F90,
  //Pin widget 0x13 - DMIC
  0x01371C00,
  0x01371D00,
  0x01371E00,
  0x01371F40,
  //Pin widget 0x14 - FRONT (Port-D)
  0x01471CF0,
  0x01471D11,
  0x01471E11,
  0x01471F41,
  //Pin widget 0x15 - I2S-OUT
  0x01571CF0,
  0x01571D11,
  0x01571E11,
  0x01571F41,
  //Pin widget 0x16 - LINE3 (Port-B)
  0x01671C10,
  0x01671D10,
  0x01671E01,
  0x01671F03,
  //Pin widget 0x17 - I2S-OUT
  0x01771C20,
  0x01771D01,
  0x01771E17,
  0x01771F90,
  //Pin widget 0x18 - I2S-IN
  0x01871CF0,
  0x01871D11,
  0x01871E11,
  0x01871F41,
  //Pin widget 0x19 - MIC2 (Port-F)
  0x01971C3E,
  0x01971D10,
  0x01971EA1,
  0x01971F04,
  //Pin widget 0x1A - LINE1 (Port-C)
  0x01A71CF0,
  0x01A71D11,
  0x01A71E11,
  0x01A71F41,
  //Pin widget 0x1B - LINE2 (Port-E)
  0x01B71C40,
  0x01B71D10,
  0x01B71EA1,
  0x01B71F03,
  //Pin widget 0x1D - PC-BEEP
  0x01D71C01,
  0x01D71D00,
  0x01D71E60,
  0x01D71F40,
  //Pin widget 0x1E - S/PDIF-OUT
  0x01E71CF0,
  0x01E71D11,
  0x01E71E11,
  0x01E71F41,
  //Pin widget 0x1F - S/PDIF-IN
  0x01F71CF0,
  0x01F71D11,
  0x01F71E11,
  0x01F71F41,
  //Pin widget 0x21 - HP-OUT (Port-I)
  0x02171C2F,
  0x02171D10,
  0x02171E21,
  0x02171F04,
  //Pin widget 0x29 - I2S-IN
  0x02971CF0,
  0x02971D11,
  0x02971E11,
  0x02971F41,

  //Widget node 0x20 - 0  FAKE JD unplug
  0x02050008,
  0x0204A80F,
  0x02050008,
  0x0204A80F,
  //Widget node 0x20 - 1 : LINE2-VREFO( MIC2-vrefo-R) base on verb_707h of NID 1Bh ,  HP-JD gating MIC2-vrefo-L, bypass DAC02 DRE(NID5B bit14)
  0x0205006B,
  0x02044260,
  0x0205006B,
  0x02044260,
  //Widget node 0x20 - 2 : //remove NID 58 realted setting for ALC700
  0x05B50010,
  0x05B45C1D,
  0x0205006F,
  0x02040F8B,   //Zeek, 0F8Bh
  //Widget node 0x20 -3 :  MIC2-Vrefo-R and MIC2-vrefo-L to independent control
  0x02050045,
  0x02045089,
  0x0205004A,
  0x0204201B,
  //Widget node 0x20 - 4   From JD detect
  0x02050008,
  0x0204A807,
  0x02050008,
  0x0204A807,
  //Widget node 0x20 - 5  Pull high ALC700 GPIO5 for AMP1305 PD pin and enable I2S BCLK first
  0x02050090,
  0x02040424,
  0x00171620,
  0x00171720,

  0x00171520,
  0x01770740,
  0x01770740,
  0x01770740,


  //Widget node 0X20 for ALC1305   20181023 update   2W/4ohm to remove ALC1305 EQ setting
  0x02050024,
  0x02040010,
  0x02050026,
  0x02040000,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400CF,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02045548,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003F,
  0x02050028,
  0x02041000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040004,
  0x02050028,
  0x02040600,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FFD0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040080,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003A,
  0x02050028,
  0x02040DFE,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x0204005D,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02040442,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040005,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040006,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040008,
  0x02050028,
  0x0204B000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204002E,
  0x02050028,
  0x02040800,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400C3,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204D4A0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400CC,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204400A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400C1,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02040320,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040039,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003B,
  0x02050028,
  0x0204FFFF,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FC20,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x02040006,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x020400C0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCA0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCE0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCF0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040080,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCE0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCA0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FC20,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x02040006,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C0,
  0x02050028,
  0x020401F0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C1,
  0x02050028,
  0x0204C1C7,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C2,
  0x02050028,
  0x02041C00,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C3,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C4,
  0x02050028,
  0x02040200,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C5,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C6,
  0x02050028,
  0x020403E1,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C7,
  0x02050028,
  0x02040F5A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C8,
  0x02050028,
  0x02041E1E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C9,
  0x02050028,
  0x0204083F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CA,
  0x02050028,
  0x020401F0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CB,
  0x02050028,
  0x0204C1C7,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CC,
  0x02050028,
  0x02041C00,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CD,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CE,
  0x02050028,
  0x02040200,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CF,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D0,
  0x02050028,
  0x020403E1,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D1,
  0x02050028,
  0x02040F5A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D2,
  0x02050028,
  0x02041E1E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D3,
  0x02050028,
  0x0204083F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040062,
  0x02050028,
  0x02048000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040063,
  0x02050028,
  0x02045F5F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040064,
  0x02050028,
  0x02042000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040065,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040066,
  0x02050028,
  0x02044004,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040067,
  0x02050028,
  0x02040802,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040068,
  0x02050028,
  0x0204890F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040069,
  0x02050028,
  0x0204E021,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040070,
  0x02050028,
  0x02048012,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040071,
  0x02050028,
  0x02043450,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040072,
  0x02050028,
  0x02040123,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040073,
  0x02050028,
  0x02044543,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040074,
  0x02050028,
  0x02042100,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040075,
  0x02050028,
  0x02044321,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040076,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040050,
  0x02050028,
  0x02048200,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040051,
  0x02050028,
  0x02040707,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040052,
  0x02050028,
  0x02044090,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x02040090,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204721F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040012,
  0x02050028,
  0x0204DFDF,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204009E,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040004,
  0x02050028,
  0x02040500,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040060,
  0x02050028,
  0x02042213,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003A,
  0x02050028,
  0x02041DFE,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003F,
  0x02050028,
  0x02043000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040040,
  0x02050028,
  0x0204000C,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040046,
  0x02050028,
  0x0204C22E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204004B,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024
);

//
// WHL codecs verb tables
//
CONST HDAUDIO_VERB_TABLE WhlHdaVerbTableAlc700 = HDAUDIO_VERB_TABLE_INIT (
  //
  //  VerbTable: (Realtek ALC700) WHL RVP
  //  Revision ID = 0xff
  //  Codec Verb Table for WHL PCH boards
  //  Codec Address: CAd value (0/1/2)
  //  Codec Vendor: 0x10EC0700
  //
  0x10EC, 0x0700,
  0xFF, 0xFF,
  //===================================================================================================
  //
  //                               Realtek Semiconductor Corp.
  //
  //===================================================================================================

  //Realtek High Definition Audio Configuration - Version : 5.0.3.1
  //Realtek HD Audio Codec : ALC700
  //PCI PnP ID : PCI\VEN_8086&DEV_2668&SUBSYS_72708086
  //HDA Codec PnP ID : HDAUDIO\FUNC_01&VEN_10EC&DEV_0700&SUBSYS_10EC10F2
  //The number of verb command block : 17

  //    NID 0x12 : 0x411111F0
  //    NID 0x13 : 0x40000000
  //    NID 0x14 : 0x411111F0
  //    NID 0x15 : 0x411111F0
  //    NID 0x16 : 0x411111F0
  //    NID 0x17 : 0x90170110
  //    NID 0x18 : 0x411111F0
  //    NID 0x19 : 0x02A19040
  //    NID 0x1A : 0x411111F0
  //    NID 0x1B : 0x411111F0
  //    NID 0x1D : 0x40638029
  //    NID 0x1E : 0x411111F0
  //    NID 0x1F : 0x411111F0
  //    NID 0x21 : 0x02211020
  //    NID 0x29 : 0x411111F0

  //===== HDA Codec Subsystem ID Verb-table =====
  //HDA Codec Subsystem ID  : 0x10EC10F2
  0x001720F2,
  0x00172110,
  0x001722EC,
  0x00172310,

  //===== Pin Widget Verb-table =====
  //Widget node 0x01 :
  0x0017FF00,
  0x0017FF00,
  0x0017FF00,
  0x0017FF00,
  //Pin widget 0x12 - DMIC
  0x01271CF0,
  0x01271D11,
  0x01271E11,
  0x01271F41,
  //Pin widget 0x13 - DMIC
  0x01371C00,
  0x01371D00,
  0x01371E00,
  0x01371F40,
  //Pin widget 0x14 - FRONT (Port-D)
  0x01471CF0,
  0x01471D11,
  0x01471E11,
  0x01471F41,
  //Pin widget 0x15 - I2S-OUT
  0x01571CF0,
  0x01571D11,
  0x01571E11,
  0x01571F41,
  //Pin widget 0x16 - LINE3 (Port-B)
  0x01671CF0,
  0x01671D11,
  0x01671E11,
  0x01671F41,
  //Pin widget 0x17 - I2S-OUT
  0x01771C10,
  0x01771D01,
  0x01771E17,
  0x01771F90,
  //Pin widget 0x18 - I2S-IN
  0x01871CF0,
  0x01871D11,
  0x01871E11,
  0x01871F41,
  //Pin widget 0x19 - MIC2 (Port-F)
  0x01971C40,
  0x01971D90,
  0x01971EA1,
  0x01971F02,
  //Pin widget 0x1A - LINE1 (Port-C)
  0x01A71CF0,
  0x01A71D11,
  0x01A71E11,
  0x01A71F41,
  //Pin widget 0x1B - LINE2 (Port-E)
  0x01B71CF0,
  0x01B71D11,
  0x01B71E11,
  0x01B71F41,
  //Pin widget 0x1D - PC-BEEP
  0x01D71C29,
  0x01D71D80,
  0x01D71E63,
  0x01D71F40,
  //Pin widget 0x1E - S/PDIF-OUT
  0x01E71CF0,
  0x01E71D11,
  0x01E71E11,
  0x01E71F41,
  //Pin widget 0x1F - S/PDIF-IN
  0x01F71CF0,
  0x01F71D11,
  0x01F71E11,
  0x01F71F41,
  //Pin widget 0x21 - HP-OUT (Port-I)
  0x02171C20,
  0x02171D10,
  0x02171E21,
  0x02171F02,
  //Pin widget 0x29 - I2S-IN
  0x02971CF0,
  0x02971D11,
  0x02971E11,
  0x02971F41,
  //Widget node 0x20 - 0  FAKE JD unplug
  0x02050008,
  0x0204A80F,
  0x02050008,
  0x0204A80F,

  //Widget node 0x20 - 1 : //remove NID 58 realted setting for ALC700  bypass DAC02 DRE(NID5B bit14)
  0x05B50010,
  0x05B45C1D,
  0x0205006F,
  0x02040F8B,   //Zeek, 0F8Bh

  //Widget node 0x20 -2:
  0x02050045,
  0x02045089,
  0x0205004A,
  0x0204201B,

  //Widget node 0x20 - 3   From JD detect
  0x02050008,
  0x0204A807,
  0x02050008,
  0x0204A807,

  //Widget node 0x20 - 4  Pull high ALC700 GPIO5 for AMP1305 PD pin and enable I2S BCLK first
  0x02050090,
  0x02040424,
  0x00171620,
  0x00171720,

  0x00171520,
  0x01770740,
  0x01770740,
  0x01770740,

  //Widget node 0x20 for ALC1305   20181105 update   2W/4ohm to remove ALC1305 EQ setting and enable ALC1305 silencet detect to prevent I2S noise
  0x02050024,
  0x02040010,
  0x02050026,
  0x02040000,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400CF,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02045548,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003F,
  0x02050028,
  0x02041000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040004,
  0x02050028,
  0x02040600,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FFD0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040080,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003A,
  0x02050028,
  0x02040DFE,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x0204005D,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02040442,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040005,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040006,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040008,
  0x02050028,
  0x0204B000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204002E,
  0x02050028,
  0x02040800,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400C3,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204D4A0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400CC,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204400A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400C1,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02040320,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040039,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003B,
  0x02050028,
  0x0204FFFF,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FC20,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x02040006,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x020400C0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCA0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCE0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCF0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040080,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCE0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FCA0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FC20,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x02040006,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C0,
  0x02050028,
  0x020401F0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C1,
  0x02050028,
  0x0204C1C7,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C2,
  0x02050028,
  0x02041C00,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C3,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C4,
  0x02050028,
  0x02040200,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C5,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C6,
  0x02050028,
  0x020403E1,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C7,
  0x02050028,
  0x02040F5A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C8,
  0x02050028,
  0x02041E1E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C9,
  0x02050028,
  0x0204083F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CA,
  0x02050028,
  0x020401F0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CB,
  0x02050028,
  0x0204C1C7,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CC,
  0x02050028,
  0x02041C00,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CD,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CE,
  0x02050028,
  0x02040200,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CF,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D0,
  0x02050028,
  0x020403E1,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D1,
  0x02050028,
  0x02040F5A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D2,
  0x02050028,
  0x02041E1E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D3,
  0x02050028,
  0x0204083F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040062,
  0x02050028,
  0x02048000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040063,
  0x02050028,
  0x02045F5F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040064,
  0x02050028,
  0x02042000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040065,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040066,
  0x02050028,
  0x02044004,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040067,
  0x02050028,
  0x02040802,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040068,
  0x02050028,
  0x0204890F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040069,
  0x02050028,
  0x0204E021,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040070,
  0x02050028,
  0x02048012,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040071,
  0x02050028,
  0x02043450,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040072,
  0x02050028,
  0x02040123,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040073,
  0x02050028,
  0x02044543,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040074,
  0x02050028,
  0x02042100,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040075,
  0x02050028,
  0x02044321,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040076,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040050,
  0x02050028,
  0x02048200,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040051,
  0x02050028,
  0x02040707,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040052,
  0x02050028,
  0x02044090,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x02040090,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204721F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040012,
  0x02050028,
  0x0204DFDF,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204009E,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040004,
  0x02050028,
  0x02040500,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040060,
  0x02050028,
  0x0204E213,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003A,
  0x02050028,
  0x02041DFE,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003F,
  0x02050028,
  0x02043000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040040,
  0x02050028,
  0x0204000C,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040046,
  0x02050028,
  0x0204422E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204004B,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024
); // WhlHdaVerbTableAlc700

#endif /* __HDA_VERB_TABLE_H__ */
