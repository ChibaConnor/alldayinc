#if defined _sampvoice_included
    #endinput
#endif
#define _sampvoice_included

#define SV_VERSION      11

#define SV_NULL         0
#define SV_INFINITY     -1
#define SV_FALSE        false
#define SV_TRUE         true

enum SV_PARAMETER
{
    SV_PARAMETER_FREQUENCY = 1,
    SV_PARAMETER_VOLUME    = 2,
    SV_PARAMETER_PANNING   = 3,
    SV_PARAMETER_EAXMIX    = 4,
    SV_PARAMETER_SRC       = 8
}

#define SV_PTR:
#define SV_STR:
#define SV_INT:
#define SV_UINT:

#define SV_STREAM:      SV_PTR:
#define SV_GSTREAM:     SV_PTR:
#define SV_LSTREAM:     SV_PTR:
#define SV_LPSTREAM:    SV_PTR:
#define SV_SLSTREAM:    SV_PTR:
#define SV_DLSTREAM:    SV_PTR:
#define SV_EFFECT:      SV_PTR:

native void:SvDebug(bool:mode);
native void:SvInit(SV_UINT:bitrate);
native SV_UINT:SvGetVersion(SV_UINT:playerid);

native bool:SvHasMicro(SV_UINT:playerid);
native bool:SvStartRecord(SV_UINT:playerid);
native bool:SvStopRecord(SV_UINT:playerid);
native bool:SvAddKey(SV_UINT:playerid, SV_UINT:keyid);
native bool:SvHasKey(SV_UINT:playerid, SV_UINT:keyid);
native bool:SvRemoveKey(SV_UINT:playerid, SV_UINT:keyid);
native void:SvRemoveAllKeys(SV_UINT:playerid);
native bool:SvMutePlayerStatus(SV_UINT:playerid);
native void:SvMutePlayerEnable(SV_UINT:playerid);
native void:SvMutePlayerDisable(SV_UINT:playerid);

native SV_GSTREAM:SvCreateGStream(SV_UINT:color = SV_NULL, SV_STR:name[] = "");
native SV_LPSTREAM:SvCreateSLStreamAtPoint(Float:distance, Float:posx, Float:posy, Float:posz, SV_UINT:color = SV_NULL, SV_STR:name[] = "");
native SV_SLSTREAM:SvCreateSLStreamAtVehicle(Float:distance, SV_UINT:vehicleid, SV_UINT:color = SV_NULL, SV_STR:name[] = "");
native SV_SLSTREAM:SvCreateSLStreamAtPlayer(Float:distance, SV_UINT:playerid, SV_UINT:color = SV_NULL, SV_STR:name[] = "");
native SV_SLSTREAM:SvCreateSLStreamAtObject(Float:distance, SV_UINT:objectid, SV_UINT:color = SV_NULL, SV_STR:name[] = "");
native SV_LPSTREAM:SvCreateDLStreamAtPoint(Float:distance, SV_UINT:maxplayers, Float:posx, Float:posy, Float:posz, SV_UINT:color = SV_NULL, SV_STR:name[] = "");
native SV_DLSTREAM:SvCreateDLStreamAtVehicle(Float:distance, SV_UINT:maxplayers, SV_UINT:vehicleid, SV_UINT:color = SV_NULL, SV_STR:name[] = "");
native SV_DLSTREAM:SvCreateDLStreamAtPlayer(Float:distance, SV_UINT:maxplayers, SV_UINT:playerid, SV_UINT:color = SV_NULL, const SV_STR:name[] = "");
native SV_DLSTREAM:SvCreateDLStreamAtObject(Float:distance, SV_UINT:maxplayers, SV_UINT:objectid, SV_UINT:color = SV_NULL, SV_STR:name[] = "");
native void:SvUpdateDistanceForLStream(SV_LSTREAM:lstream, Float:distance);
native void:SvUpdatePositionForLPStream(SV_LPSTREAM:lpstream, Float:posx, Float:posy, Float:posz);
native bool:SvAttachListenerToStream(SV_STREAM:stream, SV_UINT:playerid);
native bool:SvHasListenerInStream(SV_STREAM:stream, SV_UINT:playerid);
native bool:SvDetachListenerFromStream(SV_STREAM:stream, SV_UINT:playerid);
native void:SvDetachAllListenersFromStream(SV_STREAM:stream);
native bool:SvAttachSpeakerToStream(SV_STREAM:stream, SV_UINT:playerid);
native bool:SvHasSpeakerInStream(SV_STREAM:stream, SV_UINT:playerid);
native bool:SvDetachSpeakerFromStream(SV_STREAM:stream, SV_UINT:playerid);
native void:SvDetachAllSpeakersFromStream(SV_STREAM:stream);
native void:SvStreamParameterSet(SV_STREAM:stream, SV_PARAMETER:parameter, Float:value);
native void:SvStreamParameterReset(SV_STREAM:stream, SV_PARAMETER:parameter);
native bool:SvStreamParameterHas(SV_STREAM:stream, SV_PARAMETER:parameter);
native Float:SvStreamParameterGet(SV_STREAM:stream, SV_PARAMETER:parameter);
native void:SvStreamParameterSlideFromTo(SV_STREAM:stream, SV_PARAMETER:parameter, Float:startvalue, Float:endvalue, SV_UINT:time);
native void:SvStreamParameterSlideTo(SV_STREAM:stream, SV_PARAMETER:parameter, Float:endvalue, SV_UINT:time);
native void:SvStreamParameterSlide(SV_STREAM:stream, SV_PARAMETER:parameter, Float:deltavalue, SV_UINT:time);
native void:SvDeleteStream(SV_STREAM:stream);

native SV_EFFECT:SvEffectCreateChorus(SV_INT:priority, Float:wetdrymix, Float:depth, Float:feedback, Float:frequency, SV_UINT:waveform, Float:delay, SV_UINT:phase);
native SV_EFFECT:SvEffectCreateCompressor(SV_INT:priority, Float:gain, Float:attack, Float:release, Float:threshold, Float:ratio, Float:predelay);
native SV_EFFECT:SvEffectCreateDistortion(SV_INT:priority, Float:gain, Float:edge, Float:posteqcenterfrequency, Float:posteqbandwidth, Float:prelowpasscutoff);
native SV_EFFECT:SvEffectCreateEcho(SV_INT:priority, Float:wetdrymix, Float:feedback, Float:leftdelay, Float:rightdelay, bool:pandelay);
native SV_EFFECT:SvEffectCreateFlanger(SV_INT:priority, Float:wetdrymix, Float:depth, Float:feedback, Float:frequency, SV_UINT:waveform, Float:delay, SV_UINT:phase);
native SV_EFFECT:SvEffectCreateGargle(SV_INT:priority, SV_UINT:ratehz, SV_UINT:waveshape);
native SV_EFFECT:SvEffectCreateI3dl2reverb(SV_INT:priority, SV_INT:room, SV_INT:roomhf, Float:roomrollofffactor, Float:decaytime, Float:decayhfratio, SV_INT:reflections, Float:reflectionsdelay, SV_INT:reverb, Float:reverbdelay, Float:diffusion, Float:density, Float:hfreference);
native SV_EFFECT:SvEffectCreateParameq(SV_INT:priority, Float:center, Float:bandwidth, Float:gain);
native SV_EFFECT:SvEffectCreateReverb(SV_INT:priority, Float:ingain, Float:reverbmix, Float:reverbtime, Float:highfreqrtratio);
native void:SvEffectAttachStream(SV_EFFECT:effect, SV_STREAM:stream);
native void:SvEffectDetachStream(SV_EFFECT:effect, SV_STREAM:stream);
native void:SvEffectDelete(SV_EFFECT:effect);
forward Call_Dead_Voice(playerid, bool: status);