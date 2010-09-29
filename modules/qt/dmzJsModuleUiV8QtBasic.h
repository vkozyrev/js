#ifndef DMZ_JS_MODULE_UI_V8_QT_BASIC_DOT_H
#define DMZ_JS_MODULE_UI_V8_QT_BASIC_DOT_H

#include <dmzJsExtV8.h>
#include <dmzJsModuleUiV8Qt.h>
#include <dmzJsV8UtilHelpers.h>
#include <dmzRuntimeLog.h>
#include <dmzRuntimePlugin.h>
#include <dmzTypesHashTableHandleTemplate.h>
#include <QtCore/QList>
//#include <QtCore/QObject>
//#include <QtCore/QPointer>
#include <QtCore/QMap>
#include <v8.h>

class QDialog;


namespace dmz {

   class JsModuleUiV8QtBasic;
   class JsModuleV8;
   class V8QtObject;


   struct JsModuleUiV8QtBasicState {

      JsModuleV8 *core;
      JsModuleUiV8QtBasic *ui;
      v8::Handle<v8::Context> context;

      JsModuleUiV8QtBasicState () : core (0), ui (0) {;}
   };


   class JsModuleUiV8QtBasic :
         public Plugin,
         public JsModuleUiV8Qt,
         public JsExtV8 {

      public:
         JsModuleUiV8QtBasic (const PluginInfo &Info, Config &local);
         ~JsModuleUiV8QtBasic ();

         // Plugin Interface
         virtual void update_plugin_state (
            const PluginStateEnum State,
            const UInt32 Level);

         virtual void discover_plugin (
            const PluginDiscoverEnum Mode,
            const Plugin *PluginPtr);

         // JsModuleUiV8Qt Interface
         virtual v8::Handle<v8::Value> create_v8_widget (QWidget *value);
         virtual v8::Handle<v8::Value> create_v8_list_widget_item (QListWidgetItem *value);

         // JsExtV8 Interface
         virtual void update_js_module_v8 (const ModeEnum Mode, JsModuleV8 &module);
         virtual void update_js_context_v8 (v8::Handle<v8::Context> context);
         virtual void update_js_ext_v8_state (const StateEnum State);

         virtual void release_js_instance_v8 (
            const Handle InstanceHandle,
            const String &InstanceName,
            v8::Handle<v8::Object> &instance);

      protected:
         struct ObsStruct {

            const Handle Observer;
            QList<V8QtObject *>list;

            ObsStruct (const Handle TheObserver) : Observer (TheObserver) {;}
            ~ObsStruct () { list.clear (); }
         };

         // Static Functions
         static JsModuleUiV8QtBasic *_to_self (const v8::Arguments &Args);

         // QUiLoader bindings
         static V8Value _uiloader_load (const v8::Arguments &Args);

         // QWidget bindings implemented in JsModuleUiV8QtBasicWidget.cpp
         static V8Value _widget_close (const v8::Arguments &Args);
         static V8Value _widget_enabled (const v8::Arguments &Args);
         static V8Value _widget_hide (const v8::Arguments &Args);
         static V8Value _widget_lookup (const v8::Arguments &Args);
         static V8Value _widget_observe (const v8::Arguments &Args);
         static V8Value _widget_show (const v8::Arguments &Args);

         // QAbstractButton bindings implemented in JsModuleUiV8QtBasicButton.cpp
         static V8Value _button_text (const v8::Arguments &Args);
         static V8Value _button_is_checked (const v8::Arguments &Args);
         static V8Value _button_set_checked (const v8::Arguments &Args);
         static V8Value _button_click (const v8::Arguments &Args);

         // QDialog bindings implemented in JsModuleUiV8QtBasicDialog.cpp
//         static V8Value _create_dialog (const v8::Arguments &Args);
         static V8Value _dialog_open (const v8::Arguments &Args);

         // QSpinBox bindings implemented in JsModuleUiV8QtBasicSpinBox.cpp
         static V8Value _spinbox_maximum (const v8::Arguments &Args);
         static V8Value _spinbox_minimum (const v8::Arguments &Args);
         static V8Value _spinbox_value (const v8::Arguments &Args);
         static V8Value _spinbox_text (const v8::Arguments &Args);

         // QComboBox bindings implemented in JsModuleUiV8QtBasicComboBox.cpp
         static V8Value _combobox_count (const v8::Arguments &Args);
         static V8Value _combobox_current_index (const v8::Arguments &Args);
         static V8Value _combobox_current_text (const v8::Arguments &Args);
         static V8Value _combobox_add_item (const v8::Arguments &Args);
         static V8Value _combobox_add_items (const v8::Arguments &Args);
         static V8Value _combobox_find_text (const v8::Arguments &Args);
         static V8Value _combobox_remove_item (const v8::Arguments &Args);
         static V8Value _combobox_clear (const v8::Arguments &Args);
         static V8Value _combobox_item_text (const v8::Arguments &Args);

         // QSlider bindings implemented in JsModuleUiV8QtBasicSlider.cpp
         static V8Value _slider_maximum (const v8::Arguments &Args);
         static V8Value _slider_minimum (const v8::Arguments &Args);
         static V8Value _slider_value (const v8::Arguments &Args);
         static V8Value _slider_is_down (const v8::Arguments &Args);

         // QDial bindings implemented in JsModuleUiV8QtBasicSlider.cpp
         static V8Value _dial_wrapping (const v8::Arguments &Args);
         static V8Value _dial_notches_visible (const v8::Arguments &Args);

         // QLineEdit bindings implemented in JsModuleUiV8QtBasicLineEdit.cpp
         static V8Value _lineEdit_text (const v8::Arguments &Args);
         static V8Value _lineEdit_clear (const v8::Arguments &Args);
         static V8Value _lineEdit_undo (const v8::Arguments &Args);
         static V8Value _lineEdit_redo (const v8::Arguments &Args);

         // QTextEdit bindings implemented in JsModuleUiV8QtBasicTextEdit.cpp
         static V8Value _textEdit_append (const v8::Arguments &Args);
         static V8Value _textEdit_clear (const v8::Arguments &Args);
         static V8Value _textEdit_redo (const v8::Arguments &Args);
         static V8Value _textEdit_undo (const v8::Arguments &Args);
         static V8Value _textEdit_text (const v8::Arguments &Args);

         // QLabel bindings implemented in JsModuleUiV8QtLabel.cpp
         static V8Value _label_text (const v8::Arguments &Args);
         static V8Value _label_word_wrap (const v8::Arguments &Args);
         static V8Value _label_clear (const v8::Arguments &Args);

         // QProgressBar bindings implemented in JsModuleUiV8QtLabel.cpp
         static V8Value _progress_bar_maximum (const v8::Arguments &Args);
         static V8Value _progress_bar_minimum (const v8::Arguments &Args);
         static V8Value _progress_bar_text (const v8::Arguments &Args);
         static V8Value _progress_bar_value (const v8::Arguments &Args);
         static V8Value _progress_bar_reset (const v8::Arguments &Args);

         // QLCDNumber bindings implemented in JsModuleUiV8QtLCDNumber.cpp
         static V8Value _lcd_number_value (const v8::Arguments &Args);

         // QListWidgetItem bindings implemented in JsModuleUiV8QtBasicListWidget.cpp
         static V8Value _list_widget_item_text (const v8::Arguments &Args);

         // QListWidget bindings implemented in JsModuleUiV8QtBasicListWidget.cpp
         static V8Value _list_widget_add_item (const v8::Arguments &Args);
         static V8Value _list_widget_current_item (const v8::Arguments &Args);
         // static V8Value _list_widget_item (const v8::Arguments &Args);

         // QStackedWidget bindings implemented in JsModuleUiV8QtBasicStackedWidget.cpp
         static V8Value _stacked_widget_add (const v8::Arguments &Args);
         static V8Value _stacked_widget_remove (const v8::Arguments &Args);
         static V8Value _stacked_widget_count (const v8::Arguments &Args);
         static V8Value _stacked_widget_current_index (const v8::Arguments &Args);
         static V8Value _stacked_widget_current_widget (const v8::Arguments &Args);
         static V8Value _stacked_widget_at (const v8::Arguments &Args);
         static V8Value _stacked_widget_index_of (const v8::Arguments &Args);


         // QMessageBox bindings implemented in JsModuleUiV8QtBasicMessageBox.cpp
         static V8Value _create_message_box (const v8::Arguments &Args);
         static V8Value _message_box_open (const v8::Arguments &Args);
         // static V8Value _message_box_critical (const v8::Arguments &Args);
         static V8Value _message_box_information (const v8::Arguments &Args);
         // static V8Value _message_box_question (const v8::Arguments &Args);
         // static V8Value _message_box_warning (const v8::Arguments &Args);

         QListWidgetItem *_to_qt_list_widget_item (V8Value value);
         QDialog *_to_qt_dialog (V8Value value);
         QWidget *_to_qt_widget (V8Value value);
         V8QtObject *_to_js_qt_object (V8Value value);

         void _init_widget ();
         void _init_button ();
         void _init_list_widget ();
         void _init_list_widget_item ();
         void _init_spinbox ();
         void _init_combobox ();
         void _init_slider ();
         void _init_lineEdit ();
         void _init_textEdit ();
         void _init_dial ();
         void _init_label ();
         void _init_progressBar ();      
         void _init_dialog ();
         void _init_message_box ();
         void _init_lcdNumber ();
         void _init_stacked_widget ();

//         void _reset_message_box_observers ();
//         void _release_message_box_observer (const Handle InstanceHandle);
//         V8QtMessageBox * _to_message_box_ptr (V8Value value);

         void _init (Config &local);

         Log _log;

         JsModuleUiV8QtBasicState _state;
         V8ValuePersist _self;

         HashTableHandleTemplate<ObsStruct> _obsTable;
         QMap<QWidget *, V8QtObject *>_widgetMap;

//         HashTableHandleTemplate<V8QtCallbackStruct> _cbTable;

         V8InterfaceHelper _qtApi;
//         V8InterfaceHelper _dialogApi;
         V8InterfaceHelper _messageBoxApi;

         V8FunctionTemplatePersist _widgetTemp;
         V8FunctionPersist _widgetCtor;

         V8FunctionTemplatePersist _buttonTemp;
         V8FunctionPersist _buttonCtor;

         V8FunctionTemplatePersist _listWidgetItemTemp;
         V8FunctionPersist _listWidgetItemCtor;

         V8FunctionTemplatePersist _listWidgetTemp;
         V8FunctionPersist _listWidgetCtor;

         V8FunctionTemplatePersist _spinBoxTemp;
         V8FunctionPersist _spinBoxCtor;

         V8FunctionTemplatePersist _comboBoxTemp;
         V8FunctionPersist _comboBoxCtor;

         V8FunctionTemplatePersist _sliderTemp;
         V8FunctionPersist _sliderCtor;

         V8FunctionTemplatePersist _dialTemp;
         V8FunctionPersist _dialCtor;

         V8FunctionTemplatePersist _lineEditTemp;
         V8FunctionPersist _lineEditCtor;

         V8FunctionTemplatePersist _textEditTemp;
         V8FunctionPersist _textEditCtor;

         V8FunctionTemplatePersist _labelTemp;
         V8FunctionPersist _labelCtor;

         V8FunctionTemplatePersist _progressBarTemp;
         V8FunctionPersist _progressBarCtor;

         V8FunctionTemplatePersist _dialogTemp;
         V8FunctionPersist _dialogCtor;

//         V8FunctionTemplatePersist _messageBoxTemp;
//         V8FunctionPersist _messageBoxCtor;

         V8FunctionTemplatePersist _lcdNumberTemp;
         V8FunctionPersist _lcdNumberCtor;

         V8FunctionTemplatePersist _stackedWidgetTemp;
         V8FunctionPersist _stackedCtor;

      private:
         JsModuleUiV8QtBasic ();
         JsModuleUiV8QtBasic (const JsModuleUiV8QtBasic &);
         JsModuleUiV8QtBasic &operator= (const JsModuleUiV8QtBasic &);
   };
};


inline dmz::JsModuleUiV8QtBasic *
dmz::JsModuleUiV8QtBasic::_to_self (const v8::Arguments &Args) {

   return (dmz::JsModuleUiV8QtBasic *)v8::External::Unwrap (Args.Data ());
}


// inline dmz::JsModuleUiV8QtBasic *
// dmz::JsModuleUiV8QtBasic::_to_object (const v8::Arguments &Args, V8QtObject *object) {
//
//    object = _to_object_ptr (Args.This ());
//    return (dmz::JsModuleUiV8QtBasic *)v8::External::Unwrap (Args.Data ());
// }


#endif // DMZ_JS_MODULE_UI_V8_QT_BASIC_DOT_H
