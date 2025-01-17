/* #Lahini
$[
    1.063,
    ["pnr1000a",[["0","0","1","1"],"0.0025","0.004","GUI_GRID"],0,1,1],
    [1200,"background",[1,"task_force_radio\pnr1000a\pnr1000a.paa",["-0.0153696 * safezoneW + safezoneX","-0.323109 * safezoneH + safezoneY","0.38292 * safezoneW","1.31752 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1602,"prev_channel",[1,"",["0.198509 * safezoneW + safezoneX","0.521995 * safezoneH + safezoneY","0.013915 * safezoneW","0.037392 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Previous channel","-1"],[]],
    [1603,"next_channel",[1,"",["0.197993 * safezoneW + safezoneX","0.479104 * safezoneH + safezoneY","0.0133996 * safezoneW","0.0406913 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Next channel","-1"],[]],
    [1604,"increase_volume",[1,"",["0.13048 * safezoneW + safezoneX","0.471406 * safezoneH + safezoneY","0.0134062 * safezoneW","0.0407 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Increase volume","-1"],[]],
    [1605,"decrease_volume",[1,"",["0.129449 * safezoneW + safezoneX","0.526394 * safezoneH + safezoneY","0.0128906 * safezoneW","0.0319 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Decrease volume","-1"],[]],
    [1606,"stereo",[1,"",["0.162948 * safezoneW + safezoneX","0.5022 * safezoneH + safezoneY","0.0159844 * safezoneW","0.0374 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Stereo settings","-1"],[]],
    [1600,"reset_channel",[1,"",["0.154187 * safezoneW + safezoneX","0.562687 * safezoneH + safezoneY","0.0340144 * safezoneW","0.0307934 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Increase volume","-1"],[]],
    [1601,"speakers",[1,"",["0.160371 * safezoneW + safezoneX","0.436214 * safezoneH + safezoneY","0.019584 * safezoneW","0.037392 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1201,"microdagr_background",[1,"task_force_radio\microdagr\microdagr.paa",["0.217953 * safezoneW + safezoneX","-0.1611 * safezoneH + safezoneY","0.551203 * safezoneW","1.1484 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"channel_edit",[1,"CH1",["0.437609 * safezoneW + safezoneX","0.3504 * safezoneH + safezoneY","0.0381562 * safezoneW","0.0528 * safezoneH"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1401,"edit",[1,"448.9",["0.476281 * safezoneW + safezoneX","0.3504 * safezoneH + safezoneY","0.0613594 * safezoneW","0.0528 * safezoneH"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1608,"clear",[1,"CLEAR",["0.435547 * safezoneW + safezoneX","0.4329 * safezoneH + safezoneY","0.0402187 * safezoneW","0.0517 * safezoneH"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1609,"enter",[1,"SET",["0.498453 * safezoneW + safezoneX","0.4318 * safezoneH + safezoneY","0.04125 * safezoneW","0.055 * safezoneH"],[0,0,0,1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]]
]
*/
class pnr1000a_radio_dialog {
    idd = IDC_PNR1000A_RADIO_DIALOG;
    movingEnable = 1;
    controlsBackground[] = { };
    objects[] = { };
    onUnload = "['OnRadioOpen', [player, TF_sw_dialog_radio, false, 'pnr1000a_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;";
    onLoad = QUOTE(if (sunOrMoon < 0.2) then { \
            ((_this select 0) displayCtrl TF_IDD_BACKGROUND) ctrlSetText 'PATHTOF(pnr1000a\ui\pnr1000a_n.paa)'; \
            ((_this select 0) displayCtrl IDC_MICRODAGR_BACKGROUND) ctrlSetText 'PATHTOF(microdagr\ui\microdagr_n.paa)'; \
        }; \
        _this call TFAR_fnc_updateProgrammatorDialog; \
    );
    controls[]= {
        QUOTE(background),
        QUOTE(prev_channel),
        QUOTE(next_channel),
        QUOTE(increase_volume),
        QUOTE(decrease_volume),
        QUOTE(stereo),
        QUOTE(reset_channel),
        QUOTE(speakers),
        QUOTE(microdagr_background),
        QUOTE(channel_edit),
        QUOTE(edit),
        QUOTE(clear),
        QUOTE(enter)
    };

    class background: RscBackPicture {
        idc = IDC_PNR1000A_BACKGROUND;
        text = QPATHTOF(pnr1000a\ui\pnr1000a.paa);
        x = QUOTE(-0.0153696 * safezoneW + safezoneX);
        y = QUOTE(-0.323109 * safezoneH + safezoneY);
        w = QUOTE(0.38292 * safezoneW);
        h = QUOTE(1.31752 * safezoneH);
        moving = 1;
    };
    class prev_channel: HiddenButton {
        idc = IDC_PNR1000A_PREV_CHANNEL;
        x = QUOTE(0.198509 * safezoneW + safezoneX);
        y = QUOTE(0.521995 * safezoneH + safezoneY);
        w = QUOTE(0.013915 * safezoneW);
        h = QUOTE(0.037392 * safezoneH);
        tooltip = ECSTRING(core,previous_channel);
        action = "[0, false] call TFAR_fnc_setChannelViaDialog;";
    };
    class next_channel: HiddenButton {
        idc = IDC_PNR1000A_NEXT_CHANNEL;
        x = QUOTE(0.197993 * safezoneW + safezoneX);
        y = QUOTE(0.479104 * safezoneH + safezoneY);
        w = QUOTE(0.0133996 * safezoneW);
        h = QUOTE(0.0406913 * safezoneH);
        tooltip = ECSTRING(core,next_channel);
        action = "[1, false] call TFAR_fnc_setChannelViaDialog;";
    };
    class increase_volume: HiddenButton {
        idc = IDC_PNR1000A_INCREASE_VOLUME;
        x = QUOTE(0.13048 * safezoneW + safezoneX);
        y = QUOTE(0.471406 * safezoneH + safezoneY);
        w = QUOTE(0.0134062 * safezoneW);
        h = QUOTE(0.0407 * safezoneH);
        tooltip = ECSTRING(core,increase_volume);
        action = "[1, false] call TFAR_fnc_setVolumeViaDialog;";
    };
    class decrease_volume: HiddenButton {
        idc = IDC_PNR1000A_DECREASE_VOLUME;
        x = QUOTE(0.129449 * safezoneW + safezoneX);
        y = QUOTE(0.526394 * safezoneH + safezoneY);
        w = QUOTE(0.0128906 * safezoneW);
        h = QUOTE(0.0319 * safezoneH);
        tooltip = ECSTRING(core,decrease_volume);
        action = "[0, false] call TFAR_fnc_setVolumeViaDialog;";
    };
    class stereo: HiddenButton {
        idc = IDC_PNR1000A_STEREO;
        x = QUOTE(0.162948 * safezoneW + safezoneX);
        y = QUOTE(0.5022 * safezoneH + safezoneY);
        w = QUOTE(0.0159844 * safezoneW);
        h = QUOTE(0.0374 * safezoneH);
        action = QUOTE( \
            [ARR_2(TF_sw_dialog_radio,((TF_sw_dialog_radio call TFAR_fnc_getCurrentSwStereo) + 1) mod TFAR_MAX_STEREO)] call TFAR_fnc_setSwStereo; \
            [TF_sw_dialog_radio] call TFAR_fnc_showRadioVolume; \
        );
        tooltip = ECSTRING(core,stereo_settings);
    };
    class reset_channel: HiddenButton {
        idc = IDC_PNR1000A_RESET_CHANNEL;
        x = QUOTE(0.154187 * safezoneW + safezoneX);
        y = QUOTE(0.562687 * safezoneH + safezoneY);
        w = QUOTE(0.0340144 * safezoneW);
        h = QUOTE(0.0307934 * safezoneH);
        tooltip = ECSTRING(core,radio_channel_1);
        action = "[TF_sw_dialog_radio, 0] call TFAR_fnc_setSwChannel; call TFAR_fnc_updateSWDialogToChannel;[TF_sw_dialog_radio, false] call TFAR_fnc_showRadioInfo;";
    };
    class speakers: HiddenRotator {
        idc = IDC_PNR1000A_SPEAKERS;
        x = QUOTE(0.160371 * safezoneW + safezoneX);
        y = QUOTE(0.436214 * safezoneH + safezoneY);
        w = QUOTE(0.019584 * safezoneW);
        h = QUOTE(0.037392 * safezoneH);
        tooltip = ECSTRING(core,speakers_settings_true);
        action = "[TF_sw_dialog_radio] call TFAR_fnc_setSwSpeakers;[TF_sw_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
    };
    class microdagr_background: RscBackPicture {
        idc = IDC_MICRODAGR_BACKGROUND;
        text = QPATHTOF(microdagr\ui\microdagr.paa);
        x = QUOTE(0.217953 * safezoneW + safezoneX);
        y = QUOTE(-0.1611 * safezoneH + safezoneY);
        w = QUOTE(0.551203 * safezoneW);
        h = QUOTE(1.1484 * safezoneH);
        moving = 1;
    };
    class channel_edit: RscEditLCD {
        idc = IDC_MICRODAGR_CHANNEL_EDIT;
        text = "CH1";
        x = QUOTE(0.437609 * safezoneW + safezoneX);
        y = QUOTE(0.3504 * safezoneH + safezoneY);
        w = QUOTE(0.0381562 * safezoneW);
        h = QUOTE(0.0528 * safezoneH);
        moving = 1;
        font = "TFAR_font_dots";
        shadow = 2;
        canModify = 0;
        tooltip = ECSTRING(core,current_channel);
    };
    class edit: RscEditLCD {
        idc = IDC_MICRODAGR_EDIT;
        text = "";
        x = QUOTE(0.476281 * safezoneW + safezoneX);
        y = QUOTE(0.3504 * safezoneH + safezoneY);
        w = QUOTE(0.0613594 * safezoneW);
        h = QUOTE(0.0528 * safezoneH);
        moving = 1;
        font = "TFAR_font_dots";
        shadow = 2;
        canModify = 1;
        tooltip = ECSTRING(core,current_freq);
        onKeyUp = QUOTE( \
            if (_this select 1 in [ARR_2(28,156)]) then { \
                [((ctrlParent (_this select 0))) displayCtrl IDC_MICRODAGR_EDIT] call TFAR_handhelds_fnc_onButtonClick_Enter; \
            }; \
        );
    };
    class clear: HiddenButton {
        idc = IDC_MICRODAGR_CLEAR;
        text = "CLR";
        x = QUOTE(0.435547 * safezoneW + safezoneX);
        y = QUOTE(0.4329 * safezoneH + safezoneY);
        w = QUOTE(0.0402187 * safezoneW);
        h = QUOTE(0.0517 * safezoneH);
        tooltip = ECSTRING(core,clear_frequency);
        font = "TFAR_font_dots";
        shadow = 2;
        action = QUOTE( \
            ctrlSetText [ARR_2(IDC_MICRODAGR_EDIT,'')]; \
            ctrlSetFocus ((findDisplay IDC_PNR1000A_RADIO_DIALOG) displayCtrl IDC_MICRODAGR_EDIT); \
        );
    };
    class enter: HiddenButton {
        idc = IDC_MICRODAGR_ENTER;
        text = "ENT";
        x = QUOTE(0.498453 * safezoneW + safezoneX);
        y = QUOTE(0.4318 * safezoneH + safezoneY);
        w = QUOTE(0.04125 * safezoneW);
        h = QUOTE(0.055 * safezoneH);
        tooltip = ECSTRING(core,set_frequency);
        font = "TFAR_font_dots";
        shadow = 2;
        onButtonClick = QUOTE([((ctrlParent (_this select 0))) displayCtrl IDC_MICRODAGR_EDIT] call TFAR_handhelds_fnc_onButtonClick_Enter;);
        action = "";
    };
};
