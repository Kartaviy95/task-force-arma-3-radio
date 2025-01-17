/* #Tunizo
$[
    1.063,
    ["anprc152_radio_dialog",[["0","0","1","1"],"0.001","0.001","GUI_GRID"],0,1,0],
    [1200,"background",[1,"task_force_radio\anprc152\152.paa",["0.0138687 * safezoneW + safezoneX","-1.28145 * safezoneH + safezoneY","0.335981 * safezoneW","2.2902 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1400,"edit",[1,"",["0.168556 * safezoneW + safezoneX","0.4824 * safezoneH + safezoneY","0.0599875 * safezoneW","0.043175 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1600,"enter",[1,"",["0.205887 * safezoneW + safezoneX","0.56985 * safezoneH + safezoneY","0.0146438 * safezoneW","0.0198 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1601,"clear",[1,"",["0.205269 * safezoneW + safezoneX","0.60285 * safezoneH + safezoneY","0.0144375 * safezoneW","0.017875 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1602,"speakers",[1,"",["0.161956 * safezoneW + safezoneX","0.658675 * safezoneH + safezoneY","0.0169125 * safezoneW","0.023925 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1603,"additional",[1,"",["0.181756 * safezoneW + safezoneX","0.659225 * safezoneH + safezoneY","0.0179438 * safezoneW","0.0231 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1401,"channel_edit",[1,"",["0.134731 * safezoneW + safezoneX","0.482125 * safezoneH + safezoneY","0.033825 * safezoneW","0.044275 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1604,"next_channel",[1,"",["0.205062 * safezoneW + safezoneX","0.63035 * safezoneH + safezoneY","0.0154688 * safezoneW","0.020075 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Increase volume","-1"],[]],
    [1605,"prev_channel",[1,"",["0.204237 * safezoneW + safezoneX","0.6584 * safezoneH + safezoneY","0.0154688 * safezoneW","0.023375 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"Decrease volume","-1"],[]],
    [1606,"stereo",[1,"",["0.139475 * safezoneW + safezoneX","0.65895 * safezoneH + safezoneY","0.0198 * safezoneW","0.024475 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
    [1607,"volume_Switch",[1,"",["0.167319 * safezoneW + safezoneX","0.0762632 * safezoneH + safezoneY","0.0400125 * safezoneW","0.201575 * safezoneH"],[-1,-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1],"","-1"],[]],
]
*/

class anprc152_radio_dialog {
    idd = IDD_ANPRC152_RADIO_DIALOG;
    movingEnable = 1;
    controlsBackground[] = { };
    objects[] = { };
    onUnload = "['OnRadioOpen', [player, TF_sw_dialog_radio, false, 'anprc152_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;";
    onLoad = QUOTE(if (sunOrMoon < 0.2) then {((_this select 0) displayCtrl TF_IDD_BACKGROUND) ctrlSetText 'PATHTOF(anprc152\ui\152_n.paa)';};);
    controls[]= {
        QUOTE(background),
        QUOTE(enter),
        QUOTE(edit),
        QUOTE(channel_edit),
        QUOTE(clear),
        QUOTE(prev_channel),
        QUOTE(next_channel),
        QUOTE(volume_Switch),
        QUOTE(stereo),
        QUOTE(additional),
        QUOTE(speakers)
    };

    class background: RscBackPicture {
        idc = IDC_ANPRC152_BACKGROUND;
        text = QPATHTOF(anprc152\ui\152.paa);
        x = QUOTE(0.0138687 * safezoneW + safezoneX);
        y = QUOTE(-1.28145 * safezoneH + safezoneY);
        w = QUOTE(0.335981 * safezoneW);
        h = QUOTE(2.2902 * safezoneH);
        moving = 1;
    };
    class edit: RscEditLCD {
        moving = 1;
        idc = IDC_ANPRC152_EDIT;
        x = QUOTE(0.168556 * safezoneW + safezoneX);
        y = QUOTE(0.4824 * safezoneH + safezoneY);
        w = QUOTE(0.0599875 * safezoneW);
        h = QUOTE(0.043175 * safezoneH);
        font = "TFAR_font_dots";
        shadow = 2;
        tooltip = ECSTRING(core,current_freq);
        canModify = 1;
        onKeyUp = QUOTE( \
            if (_this select 1 in [ARR_2(28,156)]) then { \
                [((ctrlParent (_this select 0))) displayCtrl IDC_ANPRC152_EDIT] call TFAR_handhelds_fnc_onButtonClick_Enter; \
            }; \
        );
    };
    class channel_edit: RscEditLCD {
        moving = 1;
        idc = IDC_ANPRC152_CHANNEL_EDIT;
        x = QUOTE(0.134731 * safezoneW + safezoneX);
        y = QUOTE(0.482125 * safezoneH + safezoneY);
        w = QUOTE(0.033825 * safezoneW);
        h = QUOTE(0.044275 * safezoneH);
        font = "TFAR_font_dots";
        shadow = 2;
        tooltip = ECSTRING(core,current_channel);
        canModify = 0;
    };
    class enter: HiddenButton {
        idc = IDC_ANPRC152_ENTER;
        x = QUOTE(0.205269 * safezoneW + safezoneX);
        y = QUOTE(0.60285 * safezoneH + safezoneY);
        w = QUOTE(0.0144375 * safezoneW);
        h = QUOTE(0.017875 * safezoneH);
        tooltip = ECSTRING(core,set_frequency);
        onButtonClick = QUOTE([((ctrlParent (_this select 0))) displayCtrl IDC_ANPRC152_EDIT] call TFAR_handhelds_fnc_onButtonClick_Enter;);
        action = "";
    };
    class clear: HiddenButton {
        idc = IDC_ANPRC152_CLEAR;
        x = QUOTE(0.205887 * safezoneW + safezoneX);
        y = QUOTE(0.56985 * safezoneH + safezoneY);
        w = QUOTE(0.0146438 * safezoneW);
        h = QUOTE(0.0198 * safezoneH);
        tooltip = ECSTRING(core,clear_frequency);
        action = QUOTE( \
            ctrlSetText [ARR_2(IDC_ANPRC152_EDIT, '')]; \
            ctrlSetFocus ((findDisplay IDD_ANPRC152_RADIO_DIALOG) displayCtrl IDC_ANPRC152_EDIT); \
        );
    };
    class additional: HiddenButton {
        idc = IDC_ANPRC152_RADIO_DIALOG_ADDITIONAL;
        x = QUOTE(0.161956 * safezoneW + safezoneX);
        y = QUOTE(0.658675 * safezoneH + safezoneY);
        w = QUOTE(0.0169125 * safezoneW);
        h = QUOTE(0.023925 * safezoneH);
        tooltip = ECSTRING(core,set_additional);
        action = "[TF_sw_dialog_radio, TF_sw_dialog_radio call TFAR_fnc_getSwChannel] call TFAR_fnc_setAdditionalSwChannel; call TFAR_fnc_updateSWDialogToChannel; [TF_sw_dialog_radio, false] call TFAR_fnc_showRadioInfo;";
    };
    class speakers: HiddenButton {
        idc = IDC_ANPRC152_SPEAKERS;
        x = QUOTE(0.181756 * safezoneW + safezoneX);
        y = QUOTE(0.659225 * safezoneH + safezoneY);
        w = QUOTE(0.0179438 * safezoneW);
        h = QUOTE(0.0231 * safezoneH);
        tooltip = ECSTRING(core,speakers_settings_true);
        action = "[TF_sw_dialog_radio] call TFAR_fnc_setSwSpeakers;[TF_sw_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
    };
    class next_channel: HiddenButton {
        idc = IDC_ANPRC152_NEXT;
        x = QUOTE(0.205062 * safezoneW + safezoneX);
        y = QUOTE(0.63035 * safezoneH + safezoneY);
        w = QUOTE(0.0154688 * safezoneW);
        h = QUOTE(0.020075 * safezoneH);
        tooltip = ECSTRING(core,next_channel);
        action = "[1, false] call TFAR_fnc_setChannelViaDialog;";
    };
    class prev_channel: HiddenButton {
        idc = IDC_ANPRC152_PREV;
        x = QUOTE(0.204237 * safezoneW + safezoneX);
        y = QUOTE(0.6584 * safezoneH + safezoneY);
        w = QUOTE(0.0154688 * safezoneW);
        h = QUOTE(0.023375 * safezoneH);
        tooltip = ECSTRING(core,previous_channel);
        action = "[0, false] call TFAR_fnc_setChannelViaDialog;";
    };
    class stereo: HiddenButton {
        idc = IDC_ANPRC152_STEREO;
        x = QUOTE(0.139475 * safezoneW + safezoneX);
        y = QUOTE(0.65895 * safezoneH + safezoneY);
        w = QUOTE(0.0198 * safezoneW);
        h = QUOTE(0.024475 * safezoneH);
        action = QUOTE( \
            [ARR_2(TF_sw_dialog_radio,((TF_sw_dialog_radio call TFAR_fnc_getCurrentSwStereo) + 1) mod TFAR_MAX_STEREO)] call TFAR_fnc_setSwStereo; \
            [TF_sw_dialog_radio] call TFAR_fnc_showRadioVolume; \
        );
        tooltip = ECSTRING(core,stereo_settings);
    };
    class volume_Switch: HiddenRotator {
        idc = -1;
        x = QUOTE(0.167319 * safezoneW + safezoneX);
        y = QUOTE(0.0762632 * safezoneH + safezoneY);
        w = QUOTE(0.0400125 * safezoneW);
        h = QUOTE(0.201575 * safezoneH);
        tooltip = ECSTRING(core,rotator_volume);
        onMouseButtonDown = "[_this select 1, false] call TFAR_fnc_setVolumeViaDialog;";
    };
};
