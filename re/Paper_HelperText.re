[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~style: ReactNative.Style.t=?,
    ~type_: [@bs.string] [ | `error | `info],
    ~visible: bool,
    ~children: React.element
  ) =>
  React.element =
  "HelperText";
