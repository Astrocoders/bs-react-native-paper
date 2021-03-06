[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Chip";

[@bs.deriving jsConverter]
type modes = [ | [@bs.as "outlined"] `outlined | [@bs.as "flat"] `flat];

[@bs.deriving abstract]
type props('a) = {
  [@bs.optional]
  mode: string,
  [@bs.optional]
  selected: bool,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  avatar: ReasonReact.reactElement,
  [@bs.optional]
  icon: 'a,
  [@bs.optional]
  style: ReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  onPress: ReactNative.Event.pressEvent => unit,
  [@bs.optional]
  onClose: ReactNative.Event.pressEvent => unit,
};

let make =
    (
      ~mode=`flat,
      ~selected=?,
      ~disabled=?,
      ~accessibilityLabel=?,
      ~avatar=?,
      ~icon=?,
      ~style=?,
      ~theme=?,
      ~onPress=?,
      ~onClose=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      switch (icon) {
      | Some(Icon.Name(name)) =>
        props(
          ~mode=modesToJs(mode),
          ~selected?,
          ~disabled?,
          ~accessibilityLabel?,
          ~avatar?,
          ~icon=Obj.magic(name),
          ~style?,
          ~theme?,
          ~onPress?,
          ~onClose?,
          (),
        )
      | Some(Icon.Element(renderFunc)) =>
        props(
          ~mode=modesToJs(mode),
          ~selected?,
          ~disabled?,
          ~accessibilityLabel?,
          ~avatar?,
          ~icon=Obj.magic(renderFunc),
          ~style?,
          ~theme?,
          ~onPress?,
          ~onClose?,
          (),
        )
      | None =>
        props(
          ~mode=modesToJs(mode),
          ~selected?,
          ~disabled?,
          ~accessibilityLabel?,
          ~avatar?,
          ~style?,
          ~theme?,
          ~onPress?,
          ~onClose?,
          (),
        )
      },
    children,
  );
