ac = 14; %number of markers on the systems MUST MATCH HERE

%% Vicon Initialization
warning 'off';

TransmitMulticast = false; 
EnableHapticFeedbackTest = false; 
HapticOnList = {'ViconAP_001';'ViconAP_002'}; 
bReadCentroids = false; 
bReadRays = false;

% Load the SDK
Client.LoadViconDataStreamSDK();

% Program options
HostName = 'localhost:801';

% Make a new client
MyClient = Client();

% Connect to a server
while ~MyClient.IsConnected().Connected
    % Direct connection
    MyClient.Connect( HostName );    
    % Multicast connection
    % MyClient.ConnectToMulticast( HostName, '224.0.0.0' );
end

% Enable some different data types
MyClient.EnableSegmentData();
MyClient.EnableMarkerData();
MyClient.EnableUnlabeledMarkerData();
MyClient.EnableDeviceData();
if bReadCentroids
    MyClient.EnableCentroidData();
end
if bReadRays
    MyClient.EnableMarkerRayData();
end

%% Get Data 
% Set the streaming mode
MyClient.SetStreamMode( StreamMode.ClientPull );

Output_GetAxisMapping = MyClient.GetAxisMapping();
% fprintf( 'Axis Mapping: X-%s Y-%s Z-%s\n', Output_GetAxisMapping.XAxis.ToString(), Output_GetAxisMapping.YAxis.ToString(), Output_GetAxisMapping.ZAxis.ToString() );

% Discover the version number
Output_GetVersion = MyClient.GetVersion();
% fprintf( 'Version: %d.%d.%d\n', Output_GetVersion.Major, Output_GetVersion.Minor, Output_GetVersion.Point );

if TransmitMulticast
    MyClient.StartTransmittingMulticast( 'localhost', '224.0.0.0' );
end

 while MyClient.GetFrame().Result.Value ~= Result.Success
%         fprintf( '.' );
 end% while
    %    fprintf( '\n' );

% read sensors
SubjectCount = MyClient.GetSubjectCount().SubjectCount;  
SubjectName = MyClient.GetSubjectName( SubjectCount ).SubjectName;   
SegmentCount = MyClient.GetSegmentCount( SubjectName ).SegmentCount; 
SegmentName = MyClient.GetSegmentName( SubjectName, SegmentCount ).SegmentName;   
MarkerCount = MyClient.GetMarkerCount( SubjectName ).MarkerCount;    
posaa = [];   
for MarkerIndex = 1:MarkerCount
    % Get the marker name
    MarkerName = MyClient.GetMarkerName( SubjectName, MarkerIndex ).MarkerName;
    % Get the marker parent
    MarkerParentName = MyClient.GetMarkerParentName( SubjectName, MarkerName ).SegmentName;
    % Get the global marker translation
    Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation( SubjectName, MarkerName );        
    posaa = [posaa; Output_GetMarkerGlobalTranslation.Translation(1) Output_GetMarkerGlobalTranslation.Translation(2) Output_GetMarkerGlobalTranslation.Translation(3)]; 
end% MarkerIndex
posaa = posaa'; 

temp = posaa;
if temp == zeros(3, ac)  
    while temp == zeros(3, ac) 
        SubjectCount = MyClient.GetSubjectCount().SubjectCount;  SubjectName = MyClient.GetSubjectName( SubjectCount ).SubjectName;   SegmentCount = MyClient.GetSegmentCount( SubjectName ).SegmentCount; SegmentName = MyClient.GetSegmentName( SubjectName, SegmentCount ).SegmentName;   MarkerCount = MyClient.GetMarkerCount( SubjectName ).MarkerCount;    
        posaa = [];   
        for MarkerIndex = 1:MarkerCount
            % Get the marker name
            MarkerName = MyClient.GetMarkerName( SubjectName, MarkerIndex ).MarkerName;
            % Get the marker parent
            MarkerParentName = MyClient.GetMarkerParentName( SubjectName, MarkerName ).SegmentName;
            % Get the global marker translation
            Output_GetMarkerGlobalTranslation = MyClient.GetMarkerGlobalTranslation( SubjectName, MarkerName );        
            posaa = [posaa; Output_GetMarkerGlobalTranslation.Translation(1) Output_GetMarkerGlobalTranslation.Translation(2) Output_GetMarkerGlobalTranslation.Translation(3)]; 
        end% MarkerIndex
        posaa = posaa'; 
        temp = posaa;
    end
end