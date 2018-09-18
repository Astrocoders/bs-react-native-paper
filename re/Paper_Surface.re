[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Surface";

let make =
    (
      ~theme: option(Js.t({..}))=?,
      ~style: option(Rebolt.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props={
      open Js.Null_undefined;
      {"style": fromOption(style), "theme": fromOption(theme)};
    },
    children,
  );