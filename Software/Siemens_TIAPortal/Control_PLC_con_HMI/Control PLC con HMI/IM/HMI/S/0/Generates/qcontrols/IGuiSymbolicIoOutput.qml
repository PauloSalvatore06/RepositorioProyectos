import QtQuick 2.0

IGuiViewBitmap
{
    id:qSymIoOutputView

    //For Dynamic loading of components
    property Item staticComponentObjRotationRect: qSymIoOutputView


    Text
    {
        id:qDisplayText
        parent : staticComponentObjRotationRect
        anchors.fill: parent
        text:qm_DisplayText
        color: qSymIoOutputView.qm_TextColor
        anchors.bottomMargin: {return qSymIoOutputView.qm_MarginBottom + qSymIoOutputView.qm_BorderWidth}
        anchors.leftMargin: {return qSymIoOutputView.qm_MarginLeft + qSymIoOutputView.qm_BorderWidth}
        anchors.rightMargin: {return qSymIoOutputView.qm_MarginRight + qSymIoOutputView.qm_BorderWidth}
        anchors.topMargin: {return qSymIoOutputView.qm_MarginTop + qSymIoOutputView.qm_BorderWidth}
        horizontalAlignment: {return qSymIoOutputView.qm_ValueVarTextAlignmentHorizontal}
        verticalAlignment: {return qSymIoOutputView.qm_ValueVarTextAlignmentVertical}
        font: qm_Font
		renderType: Text.NativeRendering
        clip:true
    } 
}

