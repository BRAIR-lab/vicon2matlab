///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) OMG Plc 2008.
// All rights reserved.  This software is protected by copyright
// law and international treaties.  No part of this software / document
// may be reproduced or distributed in any form or by any means,
// whether transiently or incidentally to some other use of this software,
// without the written permission of the copyright owner.
//
///////////////////////////////////////////////////////////////////////////////
//
// Real Time Client Stream API Header file.
// Version 1.8.0
// 
///////////////////////////////////////////////////////////////////////////////
// Exported DLL functions listed below:
///////////////////////////////////////////////////////////////////////////////
// N.B. These are declared without extern "C" as MATLAB doesn't in general (64 bit) 
// seem to be willing to parse them, although this contradicts the cpp file

#ifdef __cplusplus
extern "C" {
#endif 

/** Construction.
 *  You can create many instances of the Vicon DataStream Client which can connect to multiple Vicon DataStream Servers.
 *  .NET is object oriented, so use the class constructor. 
 *  
 *  Because objects are lazily garbage collected, your instance may outlive the last reference to it for some time. 
 *  
 *  If the instance is pre-fetching frame data for you, then it can still use CPU and network bandwidth. 
 *  
 *  Consider explicitly disconnecting prior to destruction.
 * 
 *       ViconDataStreamSDK.DotNET.Client pHeapClient = new ViconDataStreamSDK.DotNET.Client(); 
 *       Output_SomeFunction Output = pHeapClient.SomeFunction(InputParam);
 *
 *       // Signal to the garbage collector that it can clean up 
 *       pHeapClient.Disconnect(); 
 *       pHeapClient = null;
*/
__declspec(dllexport)
unsigned int ConstructInstance_v2();

__declspec(dllexport)
void DestroyInstance_v2( unsigned int i_InstanceID );

__declspec(dllexport)
void GetVersion_v2( unsigned int   i_InstanceID, 
                    unsigned int * o_pMajor, 
                    unsigned int * o_pMinor, 
                    unsigned int * o_pPoint,
                    unsigned int * o_pRevision );

__declspec(dllexport) 
void Connect_v2( unsigned int   i_InstanceID, 
                 const char   * i_pHostname, 
                 unsigned int * o_pResult );

__declspec(dllexport) 
void ConnectToMulticast_v2( unsigned int   i_InstanceID, 
                            const char   * i_pHostname, 
                            const char   * i_pMulticastIP, 
                            unsigned int * o_pResult );

__declspec(dllexport) 
void Disconnect_v2( unsigned int   i_InstanceID, 
                    unsigned int * o_pResult );

__declspec(dllexport) 
bool IsConnected_v2( unsigned int i_InstanceID );

__declspec(dllexport) 
void StartTransmittingMulticast_v2( unsigned int   i_InstanceID,
                                    const char   * i_pServerIP,
                                    const char   * i_pMulticastIP,
                                    unsigned int * o_pResult );

__declspec(dllexport) 
void StopTransmittingMulticast_v2( unsigned int   i_InstanceID,
                                   unsigned int * o_pResult );

__declspec(dllexport) 
void EnableSegmentData_v2( unsigned int   i_InstanceID, 
                           unsigned int * o_pResult );

__declspec(dllexport)
void EnableLightweightSegmentData( unsigned int  i_InstanceID,
                                unsigned int * o_pResult );

__declspec(dllexport) 
void EnableMarkerData_v2( unsigned int   i_InstanceID, 
                          unsigned int * o_pResult );

__declspec(dllexport) 
void EnableUnlabeledMarkerData_v2( unsigned int   i_InstanceID, 
                                   unsigned int * o_pResult );

__declspec( dllexport )
void EnableMarkerRayData_v2( unsigned int   i_InstanceID,
                             unsigned int * o_pResult );

__declspec( dllexport )
void EnableDeviceData_v2( unsigned int   i_InstanceID, 
                          unsigned int * o_pResult );

__declspec(dllexport) 
void EnableCentroidData_v2( unsigned int   i_InstanceID, 
                            unsigned int * o_pResult );

__declspec(dllexport) 
void DisableSegmentData_v2( unsigned int   i_InstanceID, 
                            unsigned int * o_pResult );

__declspec(dllexport) 
void DisableLightweightSegmentData( unsigned int   i_InstanceID, 
                                    unsigned int * o_pResult );

__declspec(dllexport) 
void DisableMarkerData_v2( unsigned int   i_InstanceID, 
                           unsigned int * o_pResult );

__declspec(dllexport) 
void DisableUnlabeledMarkerData_v2( unsigned int   i_InstanceID, 
                                    unsigned int * o_pResult );

__declspec( dllexport )
void DisableMarkerRayData_v2( unsigned int   i_InstanceID,
                              unsigned int * o_pResult );

__declspec(dllexport) 
void DisableDeviceData_v2( unsigned int   i_InstanceID, 
                           unsigned int * o_pResult );

__declspec(dllexport) 
void DisableCentroidData_v2( unsigned int   i_InstanceID, 
                             unsigned int * o_pResult );


__declspec(dllexport) 
bool IsSegmentDataEnabled_v2( unsigned int i_InstanceID );

__declspec(dllexport) 
bool IsLightweightSegmentDataEnabled( unsigned int i_InstanceID );

__declspec(dllexport) 
bool IsMarkerDataEnabled_v2( unsigned int i_InstanceID );

__declspec(dllexport) 
bool IsUnlabeledMarkerDataEnabled_v2( unsigned int i_InstanceID );

__declspec( dllexport )
bool IsMarkerRayDataEnabled_v2( unsigned int   i_InstanceID );

__declspec(dllexport) 
bool IsDeviceDataEnabled_v2( unsigned int i_InstanceID );

__declspec(dllexport) 
bool IsCentroidDataEnabled_v2( unsigned int i_InstanceID );


__declspec(dllexport)
void SetBufferSize( unsigned int i_InstanceID,
                    unsigned int i_BufferSize );

__declspec(dllexport) 
void SetStreamMode_v2( unsigned int   i_InstanceID, 
                       unsigned int   i_Mode, 
                       unsigned int * o_pResult );
__declspec(dllexport) 
void SetApexDeviceFeedback_v2( unsigned int i_InstanceId, const char * i_pDeviceName, bool i_bOn, unsigned int * o_pResult );

__declspec(dllexport) 
void SetAxisMapping_v2( unsigned int   i_InstanceID, 
                        unsigned int   i_XAxis, 
                        unsigned int   i_YAxis, 
                        unsigned int   i_ZAxis, 
                        unsigned int * o_pResult );

__declspec(dllexport) 
void GetAxisMapping_v2( unsigned int   i_InstanceID, 
                        unsigned int * o_pXAxis, 
                        unsigned int * o_pYAxis, 
                        unsigned int * o_pZAxis );

__declspec(dllexport) 
void GetServerOrientation_v2( unsigned int i_InstanceID,
                              unsigned int *o_pResult, 
                              unsigned int *o_pOrientation );

__declspec(dllexport) 
void GetFrame_v2( unsigned int   i_InstanceID, 
                  unsigned int * o_pResult );

__declspec(dllexport) 
void GetFrameNumber_v2( unsigned int   i_InstanceID, 
                        unsigned int * o_pFrameNumber, 
                        unsigned int * o_pResult );

__declspec(dllexport) 
void GetTimecode_v2( unsigned int i_InstanceID, 
                     unsigned int * o_pHours, 
                     unsigned int * o_pMinutes, 
                     unsigned int * o_pSeconds, 
                     unsigned int * o_pFrames, 
                     unsigned int * o_pSubFrame, 
                     unsigned int * o_pFieldFlag,
                     unsigned int * o_ppStandard, 
                     unsigned int * o_pSubFramesPerFrame, 
                     unsigned int * o_pUserBits, 
                     unsigned int * o_pResult );

__declspec(dllexport) 
void GetFrameRate( unsigned int i_InstanceID, 
                     double * o_pFrameRate,
                     unsigned int * o_pResult );

__declspec(dllexport) 
void GetLatencySampleCount_v2( unsigned int   i_InstanceID, 
                               unsigned int * o_pCount, 
                               unsigned int * o_pResult );

__declspec(dllexport) 
const char * GetLatencySampleName_v2( unsigned int   i_InstanceID, 
                                      unsigned int   i_OneBasedLatencySampleIndex, 
                                      unsigned int * o_pResult );

__declspec(dllexport) 
void GetLatencySampleValue_v2( unsigned int   i_InstanceID, 
                               const char   * i_pLatencySampleName,
                               double       * o_pLatency,
                               unsigned int * o_pResult );

__declspec(dllexport) 
void GetLatencyTotal_v2( unsigned int   i_InstanceID, 
                         double       * o_pLatency,
                         unsigned int * o_pResult );

__declspec(dllexport) 
void GetFrameRateCount( unsigned int   i_InstanceID, 
                        unsigned int * o_pCount, 
                        unsigned int * o_pResult );

__declspec(dllexport) 
const char * GetFrameRateName( unsigned int   i_InstanceID, 
                               unsigned int   i_OneBasedFrameRateIndex, 
                               unsigned int * o_pResult );

__declspec(dllexport) 
void GetFrameRateValue( unsigned int   i_InstanceID, 
                        const char   * i_pFrameRateName,
                        double       * o_pLatency,
                        unsigned int * o_pResult );


__declspec(dllexport) 
void GetSubjectCount_v2( unsigned int   i_InstanceID, 
                         unsigned int * o_pSubjectCount, 
                         unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetSubjectName_v2( unsigned int   i_InstanceID, 
                               unsigned int   i_OneBasedSubjectIndex, 
                               unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetSubjectRootSegmentName_v2( unsigned int   i_InstanceID, 
                                          const char   * i_pSubjectName, 
                                          unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentCount_v2( unsigned int   i_InstanceID, 
                         const char   * i_pSubjectName, 
                         unsigned int * o_pSegmentCount, 
                         unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetSegmentName_v2( unsigned int   i_InstanceID, 
                               const char   * i_pSubjectName, 
                               unsigned int   i_OneBasedSegmentIndex, 
                               unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetSegmentParentName_v2( unsigned int   i_InstanceID, 
                                     const char   * i_pSubjectName, 
                                     const char   * i_pSegmentName, 
                                     unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentChildCount_v2( unsigned int   i_InstanceID, 
                              const char   * i_pSubjectName, 
                              const char   * i_pSegmentName, 
                              unsigned int * o_pSegmentCount, 
                              unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetSegmentChildName_v2( unsigned int   i_InstanceID, 
                                    const char   * i_pSubjectName, 
                                    const char   * i_pSegmentName, 
                                    unsigned int   i_OneBasedSegmentIndex, 
                                    unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentStaticTranslation_v2( unsigned int   i_InstanceID, 
                                     const char   * i_pSubjectName, 
                                     const char   * i_pSegmentName, 
                                     double         o_pTranslation[ 3 ],
                                     unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentStaticRotationHelical_v2( unsigned int   i_InstanceID, 
                                         const char   * i_pSubjectName, 
                                         const char   * i_pSegmentName, 
                                         double         o_pRotation[ 3 ],
                                         unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentStaticRotationMatrix_v2( unsigned int   i_InstanceID, 
                                        const char   * i_pSubjectName, 
                                        const char   * i_pSegmentName, 
                                        double         o_pRotation[ 9 ],
                                        unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentStaticRotationQuaternion_v2( unsigned int   i_InstanceID, 
                                            const char   * i_pSubjectName, 
                                            const char   * i_pSegmentName, 
                                            double         o_pRotation[ 4 ],
                                            unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentStaticRotationEulerXYZ_v2( unsigned int   i_InstanceID, 
                                          const char   * i_pSubjectName, 
                                          const char   * i_pSegmentName, 
                                          double         o_pRotation[ 3 ],
                                          unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentGlobalTranslation_v2( unsigned int   i_InstanceID, 
                                     const char   * i_pSubjectName, 
                                     const char   * i_pSegmentName, 
                                     double         o_pTranslation[ 3 ], 
                                     unsigned int * o_pOccluded,
                                     unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentGlobalRotationHelical_v2( unsigned int   i_InstanceID, 
                                         const char   * i_pSubjectName, 
                                         const char   * i_pSegmentName, 
                                         double         o_pRotation[ 3 ], 
                                         unsigned int * o_pOccluded,
                                         unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentGlobalRotationMatrix_v2( unsigned int   i_InstanceID, 
                                        const char   * i_pSubjectName, 
                                        const char   * i_pSegmentName, 
                                        double         o_pRotation[ 9 ], 
                                        unsigned int * o_pOccluded,
                                        unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentGlobalRotationQuaternion_v2( unsigned int   i_InstanceID, 
                                            const char   * i_pSubjectName, 
                                            const char   * i_pSegmentName, 
                                            double         o_pRotation[ 4 ], 
                                            unsigned int * o_pOccluded,
                                            unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentGlobalRotationEulerXYZ_v2( unsigned int   i_InstanceID, 
                                          const char   * i_pSubjectName, 
                                          const char   * i_pSegmentName, 
                                          double         o_pRotation[ 3 ], 
                                          unsigned int * o_pOccluded,
                                          unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentLocalTranslation_v2( unsigned int   i_InstanceID, 
                                    const char   * i_pSubjectName, 
                                    const char   * i_pSegmentName, 
                                    double         o_pTranslation[ 3 ], 
                                    unsigned int * o_pOccluded,
                                    unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentLocalRotationHelical_v2( unsigned int   i_InstanceID, 
                                        const char   * i_pSubjectName, 
                                        const char   * i_pSegmentName, 
                                        double         o_pRotation[ 3 ], 
                                        unsigned int * o_pOccluded,
                                        unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentLocalRotationMatrix_v2( unsigned int   i_InstanceID, 
                                       const char   * i_pSubjectName, 
                                       const char   * i_pSegmentName, 
                                       double         o_pRotation[ 9 ], 
                                       unsigned int * o_pOccluded,
                                       unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentLocalRotationQuaternion_v2( unsigned int   i_InstanceID, 
                                           const char   * i_pSubjectName, 
                                           const char   * i_pSegmentName, 
                                           double         o_pRotation[ 4 ], 
                                           unsigned int * o_pOccluded,
                                           unsigned int * o_pResult );

__declspec(dllexport) 
void GetSegmentLocalRotationEulerXYZ_v2( unsigned int   i_InstanceID, 
                                         const char   * i_pSubjectName, 
                                         const char   * i_pSegmentName, 
                                         double         o_pRotation[ 3 ], 
                                         unsigned int * o_pOccluded,
                                         unsigned int * o_pResult );

__declspec(dllexport) 
void GetObjectQuality_v2( unsigned int i_InstanceID,
                          const char   * i_pObjectName,
                          double       *o_pQuality,
                          unsigned int *o_pResult );
  
__declspec(dllexport) 
void GetMarkerCount_v2( unsigned int   i_InstanceID, 
                        const char   * i_pSubjectName, 
                        unsigned int * o_pMarkerCount, 
                        unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetMarkerName_v2( unsigned int   i_InstanceID, 
                              const char   * i_pSubjectName, 
                              unsigned int   i_OneBasedMarkerIndex, 
                              unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetMarkerParentName_v2( unsigned int   i_InstanceID, 
                                    const char   * i_pSubjectName, 
                                    const char   * i_pMarkerName, 
                                    unsigned int * o_pResult );

__declspec(dllexport) 
void GetMarkerGlobalTranslation_v2( unsigned int   i_InstanceID, 
                                    const char   * i_pSubjectName, 
                                    const char   * i_pMarkerName, 
                                    double         o_pTranslation[ 3 ], 
                                    unsigned int * o_pOccluded,
                                    unsigned int * o_pResult );

__declspec( dllexport )
void GetMarkerRayContributionCount_v2( unsigned int   i_InstanceID,
                                       const char   * i_pSubjectName,
                                       const char   * i_pMarkerName,
                                       unsigned int * o_pContributionCount,
                                       unsigned int * o_pResult );

__declspec( dllexport )
void GetMarkerRayContribution_v2( unsigned int   i_InstanceID,
                                  const char   * i_pSubjectName,
                                  const char   * i_pMarkerName,
                                  unsigned int   i_OneBasedMarkerRayContributionIndex,
                                  unsigned int * o_pCameraID,
                                  unsigned int * o_pCentroidIndex,
                                  unsigned int * o_pResult );

__declspec( dllexport )
void GetUnlabeledMarkerCount_v2( unsigned int   i_InstanceID, 
                                 unsigned int * o_pMarkerCount, 
                                 unsigned int * o_pResult );

__declspec(dllexport) 
void GetUnlabeledMarkerGlobalTranslation_v2( unsigned int   i_InstanceID, 
                                             unsigned int   i_OneBasedMarkerIndex, 
                                             double         o_pTranslation[ 3 ],
                                             unsigned int * o_pMarkerID,
                                             unsigned int * o_pResult );

__declspec(dllexport)
void GetLabeledMarkerCount_v2(unsigned int   i_InstanceID,
  unsigned int * o_pMarkerCount,
  unsigned int * o_pResult);

__declspec(dllexport)
void GetLabeledMarkerGlobalTranslation_v2(unsigned int   i_InstanceID,
  unsigned int   i_OneBasedMarkerIndex,
  double         o_pTranslation[3],
  unsigned int * o_pMarkerID,
  unsigned int * o_pResult);

__declspec(dllexport) 
void GetDeviceCount_v2( unsigned int   i_InstanceID, 
                        unsigned int * o_pDeviceCount, 
                        unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetDeviceName_v2( unsigned int   i_InstanceID, 
                              unsigned int   i_OneBasedDeviceIndex, 
                              unsigned int * o_pDeviceType,
                              unsigned int * o_pResult );

__declspec(dllexport) 
void GetDeviceOutputCount_v2( unsigned int   i_InstanceID, 
                              const char   * i_pDeviceName,
                              unsigned int * o_pDeviceOutputCount, 
                              unsigned int * o_pResult );

__declspec(dllexport) 
const char* GetDeviceOutputName_v2( unsigned int   i_InstanceID, 
                                    const char   * i_pDeviceName,
                                    unsigned int   i_OneBasedDeviceOutputIndex, 
                                    unsigned int * o_pDeviceOutputUnit,
                                    unsigned int * o_pResult );

__declspec( dllexport )
const char* GetDeviceComponentOutputName_v2( unsigned int   i_InstanceID,
                                    const char   * i_pDeviceName,
                                    unsigned int   i_OneBasedDeviceOutputIndex,
                                    unsigned int * o_pDeviceOutputUnit,
                                    unsigned int * o_pResult );

__declspec( dllexport )
const char* GetDeviceComponentName_v2( unsigned int   i_InstanceID,
                                    const char   * i_pDeviceName,
                                    unsigned int   i_OneBasedDeviceOutputIndex,
                                    unsigned int * o_pDeviceOutputUnit,
                                    unsigned int * o_pResult );

__declspec(dllexport)
void GetDeviceOutputSubsamples_v2( unsigned int   i_InstanceID, 
                                   const char   * i_pDeviceName, 
                                   const char   * i_pDeviceOutputName, 
                                   unsigned int * o_pSubsamples, 
                                   unsigned int * o_pOccluded,
                                   unsigned int * o_pResult );

__declspec( dllexport )
void GetDeviceOutputComponentSubsamples_v2( unsigned int   i_InstanceID,
                                   const char   * i_pDeviceName,
                                   const char   * i_pDeviceOutputName,
                                   const char   * i_pDeviceOutputComponentName,
                                   unsigned int * o_pSubsamples,
                                   unsigned int * o_pOccluded,
                                   unsigned int * o_pResult );

__declspec(dllexport)
void GetDeviceOutputValue_v2( unsigned int   i_InstanceID, 
                              const char   * i_pDeviceName, 
                              const char   * i_pDeviceOutputName, 
                              double       * o_pValue, 
                              unsigned int * o_pOccluded,
                              unsigned int * o_pResult );

__declspec( dllexport )
void GetDeviceOutputComponentValue_v2( unsigned int   i_InstanceID,
                              const char   * i_pDeviceName,
                              const char   * i_pDeviceOutputName,
                              const char   * i_pDeviceOutputComponentName,
                              double       * o_pValue,
                              unsigned int * o_pOccluded,
                              unsigned int * o_pResult );

__declspec(dllexport) 
void GetDeviceOutputSubsample_v2( unsigned int   i_InstanceID, 
                                  const char   * i_pDeviceName, 
                                  const char   * i_pDeviceOutputName, 
                                  unsigned int   i_pOneBasedSubsampleIndex,
                                  double       * o_pValue, 
                                  unsigned int * o_pOccluded,
                                  unsigned int * o_pResult );


__declspec( dllexport )
void GetDeviceOutputComponentSubsample_v2( unsigned int   i_InstanceID,
                                  const char   * i_pDeviceName,
                                  const char   * i_pDeviceOutputName,
                                  const char   * i_pDeviceOutputComponentName,
                                  unsigned int   i_pOneBasedSubsampleIndex,
                                  double       * o_pValue,
                                  unsigned int * o_pOccluded,
                                  unsigned int * o_pResult );

__declspec(dllexport)
void GetForcePlateCount_v2( unsigned int  i_InstanceID, 
                            unsigned int *o_pForcePlateCount, 
                            unsigned int *o_pResult );

__declspec(dllexport) 
void GetGlobalForceVector_v2( unsigned int   i_InstanceID, 
                              unsigned int   i_OneBasedForcePlateIndex, 
                              double         o_pVector[ 3 ], 
                              unsigned int * o_pResult );

__declspec(dllexport) 
void GetGlobalMomentVector_v2( unsigned int   i_InstanceID, 
                               unsigned int   i_OneBasedForcePlateIndex, 
                               double         o_pVector[ 3 ], 
                               unsigned int * o_pResult );

__declspec(dllexport) 
void GetGlobalCentreOfPressure_v2( unsigned int   i_InstanceID, 
                                   unsigned int   i_OneBasedForcePlateIndex, 
                                   double         o_pVector[ 3 ], 
                                   unsigned int * o_pResult );

__declspec(dllexport) 
void GetForcePlateSubsamples_v2( unsigned int  i_InstanceID, 
                                 unsigned int  i_OneBasedForcePlateIndex, 
                                 unsigned int *o_pForcePlateSubsamples, 
                                 unsigned int *o_pResult );

__declspec(dllexport) 
void GetGlobalForceVectorSubsample_v2( unsigned int   i_InstanceID, 
                                       unsigned int   i_OneBasedForcePlateIndex, 
                                       unsigned int   i_OneBasedForcePlateSubsample, 
                                       double         o_pVector[ 3 ], 
                                       unsigned int * o_pResult );

__declspec(dllexport) 
void GetGlobalMomentVectorSubsample_v2( unsigned int   i_InstanceID, 
                                        unsigned int   i_OneBasedForcePlateIndex, 
                                        unsigned int   i_OneBasedForcePlateSubsample, 
                                        double         o_pVector[ 3 ], 
                                        unsigned int * o_pResult );

__declspec(dllexport) 
void GetGlobalCentreOfPressureSubsample_v2( unsigned int   i_InstanceID, 
                                            unsigned int   i_OneBasedForcePlateIndex, 
                                            unsigned int   i_OneBasedForcePlateSubsample, 
                                            double         o_pVector[ 3 ], 
                                            unsigned int * o_pResult );

__declspec(dllexport) 
void GetEyeTrackerCount_v2( unsigned int  i_InstanceID, 
                            unsigned int *o_pEyeTrackerCount, 
                            unsigned int *o_pResult );

__declspec(dllexport) 
void GetEyeTrackerGlobalPosition_v2( unsigned int   i_InstanceID, 
                                     unsigned int   i_OneBasedEyeTrackerIndex, 
                                     double         o_pPosition[ 3 ], 
                                     unsigned int * o_pOccluded,
                                     unsigned int * o_pResult );

__declspec(dllexport) 
void GetEyeTrackerGlobalGazeVector_v2( unsigned int   i_InstanceID, 
                                       unsigned int   i_OneBasedEyeTrackerIndex, 
                                       double         o_pGazeVector[ 3 ], 
                                       unsigned int * o_pOccluded,
                                       unsigned int * o_pResult );

__declspec(dllexport)
void GetCameraCount_v2( unsigned int  i_InstanceID, 
                        unsigned int *o_pCameraCount, 
                        unsigned int *o_pResult );

__declspec(dllexport) 
const char* GetCameraName_v2( unsigned int  i_InstanceID, 
                              unsigned int  i_OneBasedCameraIndex, 
                              unsigned int *o_pResult );

__declspec(dllexport)
void GetCameraId_v2( unsigned int  i_InstanceID,
                     const char   * i_pCameraName,
                     unsigned int *o_pId,
                     unsigned int *o_pResult);

__declspec(dllexport)
void GetCameraUserId_v2( unsigned int  i_InstanceID,
                         const char   * i_pCameraName,
                         unsigned int * o_pUserId,
                         unsigned int *o_pResult);

__declspec(dllexport)
const char* GetCameraType_v2( unsigned int  i_InstanceID,
                              const char   * i_pCameraName,
                              unsigned int *o_pResult);

__declspec(dllexport)
const char* GetCameraDisplayName_v2( unsigned int  i_InstanceID,
                                     const char   * i_pCameraName,
                                     unsigned int *o_pResult);

__declspec(dllexport)
void GetCameraResolution_v2( unsigned int  i_InstanceID,
                             const char   * i_pCameraName,
                             unsigned int * o_pResolutionX,
                             unsigned int * o_pResolutionY,
                             unsigned int *o_pResult);

__declspec(dllexport)
void GetIsVideoCamera_v2( unsigned int  i_InstanceID,
                          const char   * i_pCameraName,
                          unsigned int * o_pIsVideoCamera,
                          unsigned int *o_pResult);

__declspec(dllexport)
void GetCentroidCount_v2( unsigned int  i_InstanceID, 
                          const char   *i_pCameraName,
                          unsigned int *o_pCentroidCount, 
                          unsigned int *o_pResult );

__declspec(dllexport)
void GetCentroidPosition_v2( unsigned int  i_InstanceID, 
                             const char   *i_pCameraName,
                             unsigned int  i_OneBasedCentroidIndex,
                             double        o_pPosition[ 2 ],
                             double       *o_pRadius,
//                             double       *o_pAccuracy,
                             unsigned int *o_pResult );

__declspec( dllexport )
void GetCentroidWeight_v2( unsigned int  i_InstanceID,
                           const char   *i_pCameraName,
                           unsigned int  i_OneBasedCentroidIndex,
                           double       *o_pWeight,
                           unsigned int *o_pResult );

__declspec(dllexport)
void ClearSubjectFilter( unsigned int  i_InstanceID,
                         unsigned int * o_pResult );
__declspec(dllexport)
void AddToSubjectFilter( unsigned int  i_InstanceID,
                         const char * i_pSubjectName,
                         unsigned int * o_pResult );

///////////////////////////////////////////////////////////////////////////////
// End of function list.
///////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif 
